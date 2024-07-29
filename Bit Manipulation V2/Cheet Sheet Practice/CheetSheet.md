## Basic Bit Manipulation Cheat Sheet

This cheat sheet provides a collection of 50 essential bit manipulation techniques and shortcuts, laying the groundwork for solving more complex problems in programming and computer science.

### Techniques & Shortcuts

1. **Set a bit**: `num |= (1 << i)`  ✅
2. **Clear a bit**: `num &= ~(1 << i)`  ✅
3. **Toggle a bit**: `num ^= (1 << i)`  ✅
4. **Check a bit**: `(num & (1 << i)) != 0`  ✅
5. **Change a bit to `0`**: `num &= ~(1 << i)`  ✅
6. **Change a bit to `1`**: `num |= (1 << i)`  ✅     
**Note : How to use a single line of code to set,clear and toggle a bit** 🔥 
```
int SetClearToggleBit(int num, int operation, int pos)
{
    return (operation == 0)? (num != (1<< post)) : 
            (operation == 1) ? (num &= ~(1<< pos)) :
            (operation == 2) ? (num ^= (1 << pos)) : num ;
}

```
**OR**    
```
number = (number | (1 << set_pos)) & ~(1 << clear_pos) ^ (1 << toggle_pos);

```
**Note** : Setting/Clearing/Toggling a Range of Bits:
```
// Set a range of bits from bit 'start' to bit 'end'
unsigned int setBitRange(unsigned int x, int start, int end) {
    unsigned int mask = ((1 << (end - start + 1)) - 1) << start;
    return x | mask;
}

// Clear a range of bits from bit 'start' to bit 'end'
unsigned int clearBitRange(unsigned int x, int start, int end) {
    unsigned int mask = ~(((1 << (end - start + 1)) - 1) << start);
    return x & mask;
}

// Toggle a range of bits from bit 'start' to bit 'end'
unsigned int toggleBitRange(unsigned int x, int start, int end) {
    unsigned int mask = ((1 << (end - start + 1)) - 1) << start;
    return x ^ mask;
}
```

7. **Lowest set bit OR Righmost Set bit**: `num & -num` ✅ 🔥
8. **Left Most Set Bit**: `log2(num)` Use math.h ✅ 🔥    
8. **Clear lowest set bit**: `num & (num - 1)` ✅ 🔥
9. **Get all 1-bits**: `~0` ✅
10. **Masking out (Clearing) last `i` bits**: `~((1 << i) - 1)`✅ 🔥
11. **Shifting a value `x` left by `n` bits**: `x << n`
12. **Shifting a value `x` right by `n` bits**: `x >> n`
13. **Multiplying by 2^n**: `num << n`
14. **Dividing by 2^n (floored)**: `num >> n`
15. **Check if number is even**: `num & 1 == 0`
16. **Check if number is odd**: `num & 1 == 1`
17. **Swap two numbers without temp variable**: `a ^= b; b ^= a; a ^= b;`✅ 🔥
18. **Turn off the rightmost 1-bit**: `n & (n - 1)`
19. **Isolate the rightmost 0-bit**: `~n & (n + 1)`✅ 🔥
20. **Check if a number is a power of two**: `n & (n - 1) == 0`
21. **Counting bits set to 1**: `while (n) { count++; n &= n - 1; }`✅ 🔥
22. **Reverse bits**: `while (num) { reverse <<= 1; if (num & 1) reverse ^= 1; num >>= 1; }`✅ 🔥
23. **Finding the log base 2 (integer)**: `int log = 0; while (n >>= 1) log++;` ✅ 🔥
24. **Find the absolute value**: `(num ^ (num >> 31)) - (num >> 31)`
    **Note** To convert negative to positive we need to flip the bit and add 1. The first part num ^ (num >> 31) flips all bits as -1 XOR with input flips all bits. Second part hwever converts to -1 making +1.         
```
    int mask = num >> (sizeof(int) * CHAR_BIT - 1);
    return (num + mask) ^ mask;
```    
25. **Conditionally negate a value without branching**: `(num ^ -flag) + flag` (where `flag` is 0 or 1)  ✅ 🔥
26. **Merge bits from two numbers**: `(a & mask) | (b & ~mask)`✅ 🔥
27. **Toggle all bits**: `~num`
28. **Extract a single bit**: `(num >> i) & 1`
29. **Copy the lowest set bit of `x` to all other bits**: `x | (x - 1)`
30. **Propagate the rightmost 1-bit to the right**: `x | (x - 1)` ✅ 🔥
31. **Get the value of the least significant bit (LSB)**: `x & (-x)`
32. **Clear all bits from the most significant bit through `i` (inclusive)**: `x & ((1 << i) - 1)` 
33. **Set all bits to 1 from bit `0` to `i`**: `(1 << (i + 1)) - 1` ✅ 🔥
34. **Round up to the next highest power of 2**: `int v; v--; v |= v >> 1; v |= v >> 2; v |= v >> 4; v |= v >> 8; v |= v >> 16; v++;` 
35. **Compute the sign of an integer**: `(v >> 31) | (!!v)` **Pending**
36. **Determine if integers `a` and `b` have opposite signs**: `((a ^ b) < 0)`
37. **Compute the minimum of `x` and `y` without branching**: `y ^ ((x ^ y) & -(x < y))`
38. **Compute the maximum of `x` and `y` without branching**: `x ^ ((x ^ y) & -(x < y))`
39. **Check if `x` is a power of 2**: `x && !(x & (x - 1))`
40. **Compute `x % (2^n)`**: `x & ((1 << n) - 1)`
41. **Toggle the rightmost contiguous string of 1s**: `x & (x + 1)`
42. **Isolate the rightmost contiguous string of 0s**: `~x & (x + 1)`
43. **Turn on the rightmost 0-bit**: `x | (x + 1)`
44. **Clear all bits from LSB to `i` (inclusive)**: `x & (~0 << (i + 1))`
45. **Set all bits to 0 from bit `0` to `i`**: `x & (~((1 << (i + 1)) - 1))`
46. **Creating a mask with bits `i` through `j` set to 1**: `((1 << (j - i + 1)) - 1) << i`
47. **Apply mask `m` to number `n`**: `n & m`
48. **Remove the rightmost bit set to 1**: `n & (n - 1)`
49. **Get all bits set to 1 in a byte**: `0xFF`
50. **Convert binary to gray code**: `n ^ (n >> 1)`

This cheat sheet is a starting point for mastering bit manipulation. Practice with real problems to deepen your understanding and proficiency.

## Bit Masking Cheat Sheet

This cheat sheet compiles 50 essential techniques and shortcuts for bit masking, providing a foundation for efficiently solving problems that require selective bit operations.

### Techniques & Shortcuts

1. **Define a mask with only the n-th bit set**: `1 << n`
2. **Set specific bits using a mask**: `num |= mask`
3. **Clear specific bits using a mask**: `num &= ~mask`
4. **Toggle specific bits using a mask**: `num ^= mask`
5. **Check if specific bits are set**: `(num & mask) == mask`
6. **Check if any bit in a mask is set**: `(num & mask) != 0`
7. **Select bits using a mask**: `num & mask`
8. **Mask out n lower bits**: `~((1 << n) - 1)`
9. **Create a mask for the lower n bits**: `(1 << n) - 1`
10. **Combine masks**: `mask1 | mask2`
11. **Find the intersection of masks**: `mask1 & mask2`
12. **Invert a mask**: `~mask`
13. **Shift a mask left by n bits**: `mask << n`
14. **Shift a mask right by n bits**: `mask >> n`
15. **Clear all bits from the most significant through to the nth bit**: `num & ((1 << n) - 1)`
16. **Set all bits from the most significant through to the nth bit**: `num | ~((1 << n) - 1)`
17. **Isolate the lowest set bit**: `num & -num`
18. **Clear the lowest set bit**: `num & (num - 1)`
19. **Set all bits to 1 from bit 0 to n**: `(1 << (n + 1)) - 1`
20. **Create a mask with bits set from m to n**: `((1 << (n - m + 1)) - 1) << m`
21. **Rotate bits left by n positions**: `(num << n) | (num >> (32 - n))`
22. **Rotate bits right by n positions**: `(num >> n) | (num << (32 - n))`
23. **Swap bits using a mask**: `(num >> n) ^ (num >> m)`
24. **Extract bits with a mask and shift right**: `(num & mask) >> n`
25. **Insert bits from x into num using mask**: `(num & ~mask) | (x & mask)`
26. **Combine two numbers with overlapping masks**: `(num1 & mask1) | (num2 & mask2)`
27. **Toggle bits outside a mask**: `num ^ ~mask`
28. **Clear bits outside a mask**: `num & mask`
29. **Shift mask and apply**: `num |= mask << n`
30. **Clear bits within a range**: `num &= ~(mask << start)`
31. **Check if a mask is fully contained in a number**: `(num & mask) == mask`
32. **Bitwise AND reduction using a mask**: `num & num & ... & num (using mask)`
33. **Create an alternating bit mask**: `0x55555555` (for even) or `0xAAAAAAAA` (for odd)
34. **Mask bits to wrap or circular shift**: `((num & mask) + shift) & mask`
35. **Apply mask to clear upper bits beyond n**: `num & ((1L << (n + 1)) - 1)`
36. **Use mask to divide by 2^n efficiently**: `num >> n`
37. **Multiply by 2^n using mask and shift**: `num << n`
38. **Conditional masking based on a condition**: `(condition ? mask : 0)`
39. **Create a mask from a range of bits set to 1**: `(1 << (high + 1)) - (1 << low)`
40. **Zero all bits except for the highest set bit**: `num & ~(num - 1)`
41. **Zero all bits except for the lowest set bit**: `num & -num`
42. **Apply mask to invert specific bits**: `num ^ mask`
43. **Use masks for encoding and decoding information**: `(encoded >> shift) & mask`
44. **Shift bits into position using a mask**: `(bits << position) & mask`
45. **Mask to check parity**: `num ^ (num >> 1) ^ (num >> 2) ^ ... & 1`
46. **Clear a range of bits from i to j**: `num & ~(((1 << (j - i + 1)) - 1) << i)`
47. **Toggle a range of bits from i to j**: `num ^ (((1 << (j - i + 1)) - 1) << i)`
48. **Generate a mask for single-bit access**: `1 << position`
49. **Convert a binary mask to hexadecimal for compact representation**: `0b1010 -> 0xA`
50. **Use masks to enforce bit field boundaries**: `num & ((1 << fieldSize) - 1)`

These 50 techniques and shortcuts for bit masking offer a solid foundation for manipulating bits with precision and efficiency. Mastery of these methods enables solving a wide array of bit-related problems in programming and computer science.


## Common Bit Masks Cheat Sheet

Bit masks are used in programming to manipulate individual bits of data. They enable selective operation on bits, such as setting, clearing, flipping, or checking the value of bits. This cheat sheet lists 50 common bit masks and their uses, serving as a guide for applying bit manipulation techniques effectively.

### Common Bit Masks & Their Uses

1. **All Zeros (`0x0`)**: Used to clear all bits.
2. **All Ones (`~0`)**: Used to set all bits to 1.
3. **Single Bit (`1 << n`)**: Targets the n-th bit to manipulate.
4. **Lower N Bits Set (`(1 << n) - 1`)**: Isolates the lowest n bits.
5. **Upper N Bits Set (`~((1 << (32 - n)) - 1)`)**: Masks the upper n bits in a 32-bit number.
6. **Clear N-th Bit (`~(1 << n)`)**: Used in combination with AND to clear the n-th bit.
7. **Toggle N-th Bit (`1 << n`)**: Used with XOR to toggle the n-th bit.
8. **Check N-th Bit Set (`1 << n`)**: Used with AND to check if the n-th bit is set.
9. **Set N-th Bit (`1 << n`)**: Used with OR to set the n-th bit.
10. **Clear Lower N Bits (`~((1 << n) - 1)`)**: Used to clear the lowest n bits.
11. **Clear Upper N Bits in 32-bit (`((1 << n) - 1)`)**: Clears the upper (32-n) bits.
12. **Even Bits Mask (`0x55555555`)**: Used to select even bits in a 32-bit integer.
13. **Odd Bits Mask (`0xAAAAAAAA`)**: Used to select odd bits in a 32-bit integer.
14. **Alternate Bits Set (`0x55555555`)**: A pattern of alternating 0s and 1s, starting with 0.
15. **Alternate Bits Cleared (`0xAAAAAAAA`)**: A pattern of alternating 0s and 1s, starting with 1.
16. **Byte Mask (`0xFF`)**: Targets a single byte.
17. **High Byte Mask (`0xFF00`)**: Isolates the high byte of a 16-bit number.
18. **Low Byte Mask (`0x00FF`)**: Isolates the low byte of a 16-bit number.
19. **Word Mask (`0xFFFF`)**: Targets a single word (16 bits).
20. **High Word Mask in 32-bit (`0xFFFF0000`)**: Isolates the high word of a 32-bit number.
21. **Low Word Mask in 32-bit (`0x0000FFFF`)**: Isolates the low word of a 32-bit number.
22. **Nibble Mask (`0xF`)**: Targets a single nibble (4 bits).
23. **Clear N-th Byte (`~(0xFF << (n*8))`)**: Clears the n-th byte of a 32-bit integer.
24. **Set N-th Byte (`0xFF << (n*8)`)**: Sets the n-th byte of a 32-bit integer.
25. **Leading Bit Mask (`0x80000000`)**: Isolates the leading bit of a 32-bit integer.
26. **Trailing Bit Mask (`0x1`)**: Isolates the trailing bit of an integer.
27. **Mask to Clear N Middle Bits (`~(((1 << n) - 1) << m)`)**: Clears n bits starting from bit m.
28. **Rotate Left Mask (`num << n | num >> (32 - n)`)**: Rotates bits left by n positions.
29. **Rotate Right Mask (`num >> n | num << (32 - n)`)**: Rotates bits right by n positions.
30. **Power of Two (`1 << n`)**: Represents a power of two, useful for setting or checking bits.
31. **Invert N Lower Bits (`~((1 << (n + 1)) - 1)`)**: Inverts the lowest n bits.
32. **Sequential Bits (`(1 << (high - low + 1)) - 1) << low`)**: Represents a sequence of bits set between positions high and low.
33. **Clear Bit Range (`~(((1 << (high - low + 1)) - 1) << low)`)**: Clears a range of bits from low to high.
34. **Set Bit Range (`(((1 << (high - low + 1)) - 1) << low)`)**: Sets a range of bits from low to high.
35. **Toggle Bit Range (`(((1 << (high - low + 1)) - 1) << low)`)**: Toggles a range of bits from low to high.
36. **Mask for Upper Half of 32-bit Integer (`0xFFFF0000`)**: Targets the upper half.
37. **Mask for Lower Half of 32-bit Integer (`0x0000FFFF`)**: Targets the lower half.
38. **Clearing the Rightmost Set Bit (`n & (n - 1)`)**: Used to clear the lowest set bit.
39. **Isolating the Rightmost Set Bit (`n & (-n)`)**: Extracts the lowest set bit.
40. **Mask for Single Bit Set at Position N (`1 << n`)**: Specifically targets the bit at position N.
41. **Composite Mask (`mask1 | mask2`)**: Combines two masks for multiple operations.
42. **Intersection of Masks (`mask1 & mask2`)**: Finds common bits set in two masks.
43. **Difference of Masks (`mask1 & ~mask2`)**: Clears bits in mask1 that are set in mask2.
44. **Shift Mask Left (`mask << n`)**: Moves the mask left by n bits.
45. **Shift Mask Right (`mask >> n`)**: Moves the mask right by n bits.
46. **Byte Alignment Mask (`~(0x3)`)**: Aligns data on a 4-byte boundary.
47. **Word Alignment Mask (`~(0x1)`)**: Aligns data on a 2-byte boundary.
48. **Dword Alignment Mask (`~(0x7)`)**: Aligns data on an 8-byte boundary.
49. **Qword Alignment Mask (`~(0xF)`)**: Aligns data on a 16-byte boundary.
50. **Mask for Bit Reversal (`Various techniques`)**: Used for reversing the bits in a byte or word.

These masks are fundamental tools for performing efficient bit manipulation, aiding in operations ranging from simple bit toggling to complex bitwise arithmetic and data alignment tasks.     

## Misc    
1. **Extract bit field from `pos` of length `len`** : 
```
// Extract bit field from `pos` of length `len`
unsigned int extractBitField(unsigned int x, int pos, int len) {
    unsigned int mask = (1 << len) - 1;
    return (x >> pos) & mask;
}
// Set bit field from `pos` of length `len` to `value`
unsigned int setBitField(unsigned int x, unsigned int value, int pos, int len) {
    unsigned int mask = (1 << len) - 1;
    return (x & ~(mask << pos)) | ((value & mask) << pos);
}
// Example: Extract 3-bit field from position 2
// x = 0x7F (Binary: 0111 1111), pos = 2, len = 3
// Extracted: 0x07 (Binary: 0000 0111)
```
2. **Set bit field from `pos` of length `len` to `value`**:    
```
unsigned int setBitField(unsigned int x, unsigned int value, int pos, int len) {
    unsigned int mask = (1 << len) - 1;   // Create a mask with 'len' bits set to 1
    x &= ~(mask << pos);                  // Clear the bits in the specified range
    x |= (value & mask) << pos;           // Set the bits in the specified range to 'value'
    return x;
}
```
3. ****
```

```

## Websites
1. https://www.topcoder.com/thrive/articles/A%20bit%20of%20fun:%20fun%20with%20bits

