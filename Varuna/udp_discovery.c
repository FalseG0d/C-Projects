// udp_discovery_master.c - Master
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8888
#define BROADCAST_IP "255.255.255.255"
#define DISCOVER_MSG "DISCOVER_SLAVES"
#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in broadcastAddr;
    char buffer[BUF_SIZE];

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Enable broadcast
    int broadcastEnable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)) < 0) {
        perror("setsockopt (SO_BROADCAST) failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Setup address structure
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_port = htons(PORT);
    broadcastAddr.sin_addr.s_addr = inet_addr(BROADCAST_IP);

    // Send broadcast
    if (sendto(sockfd, DISCOVER_MSG, strlen(DISCOVER_MSG), 0,
               (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr)) < 0) {
        perror("Broadcast send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("[Master] Discovery message sent. Listening for responses...\n");

    // Listen for replies
    struct sockaddr_in slaveAddr;
    socklen_t addr_len = sizeof(slaveAddr);
    while (1) {
        int len = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr*)&slaveAddr, &addr_len);
        if (len > 0) {
            buffer[len] = '\0';
            printf("[Master] Received reply from %s: %s\n", inet_ntoa(slaveAddr.sin_addr), buffer);
        }
    }

    close(sockfd);
    return 0;
}
