#include <stdio.h>

static int squareOf[] = {
    [1] = 1,
    [2] = 4,
    [3] = 9,
    [4] = 16,
    [5] = 25,
};

static char caseConvert[] = {
    ['a'] = 'A',
    ['b'] = 'B',
    ['c'] = 'C',
    ['d'] = 'D',
    ['e'] = 'E'
};

int main() {
    printf("%d\n", squareOf[4]);
    printf("%c\n", caseConvert['d']);

    return 0;
}