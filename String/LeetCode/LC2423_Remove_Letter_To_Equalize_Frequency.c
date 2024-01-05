#include <stdio.h>

int main() {
    printf("Size of '7': %lu bytes\n", sizeof('7'));
    printf("Size of 7: %lu bytes\n", sizeof(7));
    printf("Size of 7.0: %lu bytes\n", sizeof(7.0));
    return 0;
}
