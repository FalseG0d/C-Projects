#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "common.h"

void receive_file(int client_socket) {
    char filename[BUFFER_SIZE];
    recv(client_socket, filename, BUFFER_SIZE, 0);

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("File open error");
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytes;
    while ((bytes = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
        if (bytes < BUFFER_SIZE) break;
    }

    fclose(fp);
    printf("File '%s' received.\n", filename);
}

void send_file(int client_socket) {
    char filename[BUFFER_SIZE];
    recv(client_socket, filename, BUFFER_SIZE, 0);

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("File open error");
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        send(client_socket, buffer, bytes, 0);
    }

    fclose(fp);
    printf("File '%s' sent to master.\n", filename);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Slave listening on port %d...\n", PORT);
    while (1) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        char command[10];
        recv(client_socket, command, sizeof(command), 0);

        if (strcmp(command, "SEND") == 0) {
            receive_file(client_socket);
        } else if (strcmp(command, "RECEIVE") == 0) {
            send_file(client_socket);
        }

        close(client_socket);
    }

    return 0;
}
