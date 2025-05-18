#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "common.h"

void send_file(int sock) {
    char src[BUFFER_SIZE], dest[BUFFER_SIZE];
    printf("Enter source file path: ");
    scanf("%s", src);
    printf("Enter destination filename on slave: ");
    scanf("%s", dest);

    send(sock, "SEND", 4, 0);
    send(sock, dest, strlen(dest) + 1, 0);

    FILE *fp = fopen(src, "rb");
    if (!fp) {
        perror("File open error");
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        send(sock, buffer, bytes, 0);
    }

    fclose(fp);
    printf("File sent.\n");
}

void receive_file(int sock) {
    char src[BUFFER_SIZE], dest[BUFFER_SIZE];
    printf("Enter source file path on slave: ");
    scanf("%s", src);
    printf("Enter destination path on master: ");
    scanf("%s", dest);

    send(sock, "RECEIVE", 7, 0);
    send(sock, src, strlen(src) + 1, 0);

    FILE *fp = fopen(dest, "wb");
    if (!fp) {
        perror("File open error");
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytes;
    while ((bytes = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
        if (bytes < BUFFER_SIZE) break;
    }

    fclose(fp);
    printf("File received.\n");
}

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char ip[50];

    printf("Enter Slave IP address: ");
    scanf("%s", ip);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    int choice;
    do {
        printf("\n1. Send Data\n2. Receive Data\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                send_file(sock);
                break;
            case 2:
                receive_file(sock);
                break;
        }
    } while (choice != 3);

    close(sock);
    return 0;
}