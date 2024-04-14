#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int setBit(int num, int pos)
{
    num |= ( 1 << pos );
    return num;
}
int clearBit(int num, int pos)
{
    num &= ~( 1 << pos );
    return num;
}
int toggleBit(int num, int pos)
{
    num  ^= (1<<pos);
    return num;
}
int checkBit(int num, int pos)
{
    return (num & (1<<pos)) != 0;
}

int SetClearToggleBit(int num, int Setpos, int Clearpos, int Togglepos) {
    return ((num | (1 << Setpos)) & ~(1 << Clearpos)) ^ (1 << Togglepos);
}

int CheckRightmostSet1(int num)
{
    return num & -num;
}
int CheckRightmostSet1ndPosition(int num)
{
    num = num & -num;
    int position = 0;
    while(num !=0)
    {
        num  = num >> 1;
        position++;
    }
    return position;
}
int CheckLeftMostSetBit(int num)
{
    /* Approach 1 */
    /* if (num == 0) return -1;
    int position = 0;
    while(num != 0)
    {
        num = num >> 1;
        position ++;
    }
    return position; */

    /* Approach 2 */
    return log2(num);
}

int ClearLeftMostBit(int num)
{
    int dum_num = num;
    // trarve and find the position of the index at which the lft most index resides
    int leftmostpos = 0;
    int position  = 0;
    while(dum_num != 0)
    {   
        if((dum_num & 1) == 1)
        {
            leftmostpos = position;
        }
        dum_num = dum_num >> 1;
        position++;
    }

    int mask = (1 << leftmostpos);
    return num & ~(mask);
}

int ClearingOut_NBits(int num, int pos)
{
    return num & ~((1<< pos) -1);
}

int IsolateRightMost0(int num)
{
    return ~num & (num + 1);
}
int ReverseBits(int num)
{
    int reverse = 0;
    while(num != 0)
    {
        reverse<<= 1;
        if (num & 1)
        {
            reverse ^= (1);
        }
        num >>= 1;
    }
    return reverse;
}
int AbsoluteValues(int num)
{
    int mask = num >> (sizeof(int) * 8 - 1);
    return (num + mask) ^ mask;
}

int ConditionalNegate(int num, int cond)
{
    int mask  = -(int)cond;
    return (num ^ mask) - mask;
}

int setallbitsfromitozero(int i)
{
    return ((1 << (i+1)) - 1);
}

int main()
{
    // set a bit 
    printf("Before setBit() Number  = %d\n After setBit() Number = %d\n", 10, setBit(10,2));
    // clear a bit
    printf("Before clearBit NUmber  = %d\n After ClearBit Number = %d\n", 10, clearBit(10,1));
    // to toggle a bit
    printf("Before Toggle a bit = %d\n After Toggle a bit = %d\n",10, toggleBit(10,1));
    printf("Before Toggle a bit = %d\n After Toggle a bit = %d\n",8, toggleBit(8,1));

    // check the bit if its 0 or 1
    printf("Bit at position %d is %d\n",3, checkBit(10,3));

    // set clear and toggle in one line 
    printf("Number %d is set at position 0 and cleared at poisition 3 and toggled at position2 : New Number is =%d\n", 8, SetClearToggleBit(8,0,2,1));

    // check rightmost set bit
    printf("Number is %d, its right most set bit is %d\n", 8, CheckRightmostSet1ndPosition(10));

    // check the left-most-set bit of a number
    printf("The nums's %d left most set bt is %d\n", 10, CheckLeftMostSetBit(10));

    // clearing out N bits
    printf("Number is %d After Clearing Out 3 bits = %d\n",255, ClearingOut_NBits(255,4));

    // Isolating right most clear bit
    printf("Numbers's = %d Rightmost Set Bit = %d\n", 9, IsolateRightMost0(9));

    // Reverse Bits
    printf("Original number: %d, Reversed number: %d\n", 10, ReverseBits(10));

    // FInding Absolute Value
    int a = -5;
    int b = 5;
    printf("The absolute value of %d is %d\n", a, AbsoluteValues(a));
    printf("The absolute value of %d is %d\n", b, AbsoluteValues(b));

    // Conditional Negate
    int num = 5;
    int shouldNegate = 1; // Change to 0 to leave `num` unchanged
    int result = ConditionalNegate(num, shouldNegate);
    
    printf("Conditional Negate of NUmber %d is Result: %d\n",num, result);

    // set all the bits from 0 to i to 1
    int i = 3;
    printf("Set all bits from i to 0 for i = %d and result = %d\n", i, setallbitsfromitozero(i));
}