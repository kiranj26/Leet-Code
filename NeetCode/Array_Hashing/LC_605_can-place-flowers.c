#include <stdio.h>
#include <stdbool.h>
/* My Approaches */

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
    int count = 0;
    for (int i = 0 ; i < flowerbedSize ; i++) {
        if (flowerbed[i] != 1)
        {
            if (i == 0){
                // check if the next element is 0
                if (flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    count ++;
                }
            }else if (i == flowerbedSize - 1)
            {
                if (flowerbed[i - 1] == 0)
                {
                    flowerbed[i] = 1;
                    count ++;
                }
            }else{
                if ( (flowerbed[i-1] == 0) && (flowerbed[i+1] == 0) )
                {
                    flowerbed[i] = 1;
                    count ++;
                }
            }
        }
        // at any stage when we have lanted required plants
        if (count >= n) return true;
    }
    return false;
}

int main() {
    int flowerbed1[] = {1, 0, 0, 0, 1};
    int n1 = 1;
    int size1 = sizeof(flowerbed1) / sizeof(flowerbed1[0]);

    bool result1 = canPlaceFlowers(flowerbed1, size1, n1);
    printf("Example 1: %s\n", result1 ? "true" : "false");

    int flowerbed2[] = {1, 0, 0, 0, 1};
    int n2 = 2;
    int size2 = sizeof(flowerbed2) / sizeof(flowerbed2[0]);

    bool result2 = canPlaceFlowers(flowerbed2, size2, n2);
    printf("Example 2: %s\n", result2 ? "true" : "false");

    int flowerbed3[] = {1,0,1,0,1,0,1};
    int n3 = 2;
    int size3 = sizeof(flowerbed3) / sizeof(flowerbed3[0]);

    bool result3 = canPlaceFlowers(flowerbed3, size3, n3);
    printf("Example 3: %s\n", result3 ? "true" : "false");

    return 0;
}
