#include <stdio.h>
#include <assert.h>

/**
 * Function: setBitField
 * ---------------------
 * Sets a bit field in an unsigned integer x to a given value.
 * 
 * Parameters:
 *   x     - The original unsigned integer.
 *   value - The value to set in the bit field.
 *   pos   - The starting position of the bit field (0-indexed).
 *   len   - The length of the bit field.
 * 
 * Returns:
 *   The modified unsigned integer after setting the specified bit field.
 * 
 * Approach:
 *   1. Create a mask with 'len' bits set to 1.
 *   2. Clear the bits in the specified range by ANDing x with the negated mask shifted to 'pos'.
 *   3. Set the bits in the specified range by ORing x with the value ANDed with the mask, then shifted to 'pos'.
 * 
 * Time Complexity:
 *   O(1) - The operations involved (bitwise shifts and logical operations) are all constant-time operations.
 * 
 * Space Complexity:
 *   O(1) - The function uses a fixed amount of extra space for variables (mask), independent of the input size.
 */
unsigned int setBitField(unsigned int x, unsigned int value, int pos, int len) {
    unsigned int mask = (1 << len) - 1;   // Create a mask with 'len' bits set to 1
    x &= ~(mask << pos);                  // Clear the bits in the specified range
    x |= (value & mask) << pos;           // Set the bits in the specified range to 'value'
    return x;
}

int main() {
    // Test case 1
    unsigned int x1 = 0xFFFF;
    unsigned int value1 = 0x5;
    int pos1 = 2;
    int len1 = 3;
    unsigned int expected1 = 0xFFEB;
    assert(setBitField(x1, value1, pos1, len1) == expected1);
    printf("Test case 1 passed!\n");

    // Test case 2
    unsigned int x2 = 0x0;
    unsigned int value2 = 0x3;
    int pos2 = 28;
    int len2 = 4;
    unsigned int expected2 = 0x30000000;
    assert(setBitField(x2, value2, pos2, len2) == expected2);
    printf("Test case 2 passed!\n");

    // Test case 3
    unsigned int x3 = 0x12345678;
    unsigned int value3 = 0xA;
    int pos3 = 8;
    int len3 = 4;
    unsigned int expected3 = 0x12345A78;
    assert(setBitField(x3, value3, pos3, len3) == expected3);
    printf("Test case 3 passed!\n");

    // Test case 4
    unsigned int x4 = 0x0;
    unsigned int value4 = 0xFFFFFFFF;
    int pos4 = 0;
    int len4 = 32;
    unsigned int expected4 = 0xFFFFFFFF;
    assert(setBitField(x4, value4, pos4, len4) == expected4);
    printf("Test case 4 passed!\n");

    // Test case 5
    unsigned int x5 = 0x12345678;
    unsigned int value5 = 0x5;
    int pos5 = 8;
    int len5 = 0;
    unsigned int expected5 = 0x12345678;
    assert(setBitField(x5, value5, pos5, len5) == expected5);
    printf("Test case 5 passed!\n");

    return 0;
}
