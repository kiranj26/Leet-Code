# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int * result =  (int *) malloc(encodedSize + 1 * sizeof(int));
    result[0] = first;
    for (int i=1;i<encodedSize + 1;i++)
    {
        result[i] = encoded[i] ^ encoded[i-1];
    }
    printf("decoding");
    *returnSize = encodedSize + 1;
    return result;
}
int main(int arg, char **argv)
{
    int encoded[] = {1,2,3};
    int first  = 1;
    int encodedSize = sizeof(encoded)/ sizeof(encoded[0]);
    int returnSize;
    printf("Encoded size: %d\n", encodedSize);

    int * result = decode(encoded, encodedSize , first, &returnSize);
    printf("Return size: %d\n", returnSize);

    free(result);



}