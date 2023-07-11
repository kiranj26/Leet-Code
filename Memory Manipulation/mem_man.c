#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//here we will be using memeory manipulation and comparision functions
// 1 memcmp() - similar to string compare but uses void pointers

void printArray(int * arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }    
    printf("\n");
}
int main(int argc, char** argv)
{
    int arr1[] = {1,2,1,4,5,6,7};
    
    int arr2[] = {1,2,3,4,5,6,7};

    // printf("%d\n",memcmp(arr1,arr2,3 * sizeof(int)));

    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    // Using memset() function
    // ----------------------------------------------------------------
    // ----------------------------------------------------------------

    // syntax 1. starting location of memmory to be filled
    // syntax 2. Value to be filled with
    // syntax 3. Mo of bted to be filled with

    char str [] ="Canoo Proprientry";
    printf("Before memset function = %s\n",str);
    memset(str,'-',2 * sizeof(char));
    printf("AFter memset function = %s\n",str);

    // works super fine with strings

    // Tricks with using memset for integer
    int arr3[] = {1,2,3,4};
    printArray(arr3,4);
    memset(arr3, 1, 4 * sizeof(int));
    // 16843009 16843009 16843009 16843009
    // output is 0x01010101 something like this

    printArray(arr3,4);

    // why this doesnt works is 
    // Short answer, NO.
    // Long answer, memset sets bytes and works for characters because they are single bytes, but integers are not.
    // most esiast will be to simply use a for loop and set first 4 array elements with specific alue 


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    // Using memcpy() function
    // ----------------------------------------------------------------
    // ----------------------------------------------------------------

    int arr5[] = {10,10,10,10};
    int arr6[] = {20,20,202,20};

   memcpy (arr5, arr6, 2 * sizeof(int));
   // memset will copy the 2 * sizeof(int) bytes from arr6 to arr5
   // here it will transfer 8 bytee
   // result will be straight away 20 20 10 10
   printArray(arr5,4);

int arr7[] = {1,2,3,4};
int arr8[] = {2550,20,20,20};
   //if I change the bytes size in second argument to 2 * sizeof(char) i.e 2 bytes only one first element will be trasferered
   memcpy (arr7, arr8, 1 * sizeof(char));
   // output seen 246 2 3 4
   // due to passing inaccurate size as third argument to the function
   printArray(arr7,4);

}


