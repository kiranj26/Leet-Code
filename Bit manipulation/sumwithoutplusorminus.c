# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


// we can use XOR and bitwise AND to achive this
// without carry
// just do a XOR with b

int sumoftwonum(int a , int b)
{
    while( b != 0) {
        int sum_without_carry = a ^ b;   // if we see how the logic operation works we know
                                        // that the 1 + 0 or 0+1 needs to be 1 for sum or maybe 0 + 0 or 1+0 neds to be 0 that here XOR comes from
        int carry = (a & b) << 1;       // Now in the case when we have 1 + 1 carry will be generated and ith 0 + 0 carry will not be generated so we will use AND to get this behaviour

        a = sum_without_carry;
        b = carry;
    }
    return a;
}

int main(int argc, char **argv)
{
    int result = sumoftwonum(12,9);
    printf("Result = %d\n",result);
    
}