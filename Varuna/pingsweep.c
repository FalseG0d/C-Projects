#include <stdio.h>
#include <stdlib.h>

void ping_sweep(const char* subnet) {
    char ip[32];
    char cmd[64];
    for (int i = 1; i < 255; i++) {
        snprintf(ip, sizeof(ip), "%s.%d", subnet, i);
        snprintf(cmd, sizeof(cmd), "ping -c 1 -W 1 %s > /dev/null", ip);
        if (system(cmd) == 0) {
            printf("Host %s is up.\n", ip);
        }
    }
}