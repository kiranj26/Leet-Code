# Lowest Set Bit
Lets say we have number 10 (1010)
1010
0101
0001
0110 (-num)

1010
0110
0010


# Clearing Lowest Set Bit
Lets say number is 8 1000
Numb -1 is 0111

so 1000
&  0111
=  0000

# Masking out (Clearing) last i bits

- (1 <<>> i)   - Sets the ith bit
- (1 << i) - 1  Makes all the bits to the right 1 except the ith bit which is 0
- ~((1 << i) - 1) Make all element ot the right of the bit 0 

Example  : 
i being 3rd bit starting from 0 
(1 << i)        -> 1000
(1 << i) - 1    -> 0111
~((1 << i) - 1) -> 1000

# Swapping Two numbers
a^= b;
b ^= a;
a ^= b;