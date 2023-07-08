# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


int hammingWeight(uint32_t num)
{
    uint32_t count = 31;
    uint32_t noof1s = 0;
    while (count != 0) 
    {
        int lastbit = num & (0x01);
        printf("num = %d\n", lastbit);
        if (lastbit != 0)
        {
            noof1s++;
        }
        num = num >> 1;
        count --;
    }
    return noof1s;
    
}

int main(int argc, char *argv[])
{
    uint32_t a = 15;
    uint32_t result = hammingWeight(a);
    printf("Hamming weight : %d\n", result);
}



