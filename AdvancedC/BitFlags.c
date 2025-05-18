#include <stdio.h>
#include <stdbool.h>

int processNumber(int num, bool x_2, bool square, bool bi_2) {
    if(x_2) num *= 2;
    if(square) num *= num;
    if(bi_2) num /= 2;
    
    return num;
}

enum Flags {
    DOUBLE = 1,
    SQUARE = 1<<1,
    HALF = 1<<2
};

int betterProcess(int num, int flags) {
    if(flags & DOUBLE) num *= 2;
    if(flags & SQUARE) num *= num;
    if(flags & HALF) num /= 2;

    printf("%d", flags && HALF);
    
    return num;
}

int main() {
    int num = 3;
    // num = processNumber(num, true, true, false);
    num = betterProcess(num, (int) DOUBLE | SQUARE);
    printf("%d", num);
    // printf("%d", 3 & 4);
    return 0;
}