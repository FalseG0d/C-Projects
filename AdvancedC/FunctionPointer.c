#include<stdio.h>

int add(int x, int y) {
    return x + y;
}

int runIntFunction(int a, int b, int(*predicate)(int,int)) {
    return predicate(a, b);
}

int main() {
    int a = 10;
    int b = 20;

    int (*addFn)(int,int) = add;

    printf("Sum: %d\n", a + b);
    printf("Sum: %d\n", addFn(a, b));
    printf("Sum: %d\n", runIntFunction(a, b, addFn));
}