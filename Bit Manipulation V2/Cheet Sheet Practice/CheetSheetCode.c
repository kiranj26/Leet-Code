#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

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

int SetClearToggleBit(int num, int Setpos, int Clearpos, int Togglepos)
{
    return (num |=  (1<< Setpos))     |
           (num &= ~(1<< Clearpos))   |
           (num ^=  (1 << Togglepos)) ;
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
    printf("Number +%d is set at position 0 and cleared at poisition 3 and toggled at position2 : New Number is =%d\n", 8, SetClearToggleBit(8,0,2,1));
}