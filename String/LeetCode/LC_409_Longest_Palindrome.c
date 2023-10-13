#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// @Note : My Ugly Approach
// @Time Complexity : Strlen O(n) , frequency O(n) Loop 0 to 51 O(n) Overall O(n)
// @ Spcae Complexity : O(1)
int longestPalindrome(char * s){
    int length = strlen(s);
    int frequency[52] = {0};

    for(int i=0;i<length;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            int index = (int)s[i] - 'a';
            frequency[index]++;
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            int index = (int)s[i] - 'A' + 25;
            frequency[index]++;
        }else
        {

        }
    }
    int odd_count =0 ;
    int even_count =0 ;
    int atleast_1_odd = 0;
    
    for(int i=0;i<52;i++)
    {
        printf("%d",frequency[i]);
        if (frequency[i] % 2 == 0)
        {
            even_count += frequency[i];
        }
        else
        {
            if(frequency[i] % 2 != 0){atleast_1_odd=1;}

            odd_count += (frequency[i] -1);
        }
    }
    printf("\nOdd Count = %d \n Even Count = %d\n Atleast 1 odd = %d\n", odd_count, even_count, atleast_1_odd);
    if (atleast_1_odd == true)
    {
        return odd_count + even_count + 1;
    }else
    {
        return odd_count + even_count;
    
    } 
}


int main() {
    char test1[] = "abccccdd";
    printf("Test 1: %d\n", longestPalindrome(test1));  // Should print 7

    char test2[] = "a";
    printf("Test 2: %d\n", longestPalindrome(test2));  // Should print 1

    char test3[] = "bb";
    printf("Test 3: %d\n", longestPalindrome(test3));  // Should print 2

    char test4[] = "ccc";
    printf("Test 4: %d\n", longestPalindrome(test4));  // Should print 2

    return 0;
}
