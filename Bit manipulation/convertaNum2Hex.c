#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toHex(int num) {
    if (num == 0) return "0";

    int size = sizeof(int) * 2;
    char *hex = malloc(sizeof(char) * (size + 1));
    int index = size - 1; // Start from the last index of the hex string

    // Traverse the bits in groups of 4
    for (int i = size - 1; i >= 0; i--) {
        int last4 = (num >> (4 * i)) & 0x0F;
        if (last4 != 0 || index < size - 1) { // Only add non-zero digits or after the first non-zero digit
            if (last4 < 10) {
                hex[index] = last4 + '0';
            } else {
                hex[index] = last4 - 10 + 'a';
            }
            index--;
        }
    }

    // traverse string to reverse it
    for (int i = 0; i < size / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[size - 1 - i];
        hex[size - 1 - i] = temp;
    }

    hex[size] = '\0'; // Add null terminator

    return hex + index + 1; // Return the substring without leading zeros
}


int main() {
    int input = -10;

    char *num = toHex(input);

    printf("\n\t Final result  = %s\n", num);

    free(num);
    return 0;
}
