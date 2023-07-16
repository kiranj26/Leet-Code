# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int count1s(int num) { 
    int count = 0;
    while(num != 0) {
        num = num & (num - 1);
        count ++;
    }
    return count;
}

int* countBits(int n, int* returnSize){
    int * result = (int *)malloc((n +1)*sizeof(int));
    for( int i=0;i< n+1;i++)
    {
        result[i] = count1s(i);
    }
    *returnSize = n +1;
    return result;

}
int main(int argc, char** argv)
{
    int n = 5;
    int size = n+1;
    int * result = countBits(n, &size);

    for(int i = 0; i < size; i++)
    {
        printf("%d",result[i]);
    }
}