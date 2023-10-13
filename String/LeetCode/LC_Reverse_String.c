#include <stdio.h>
#include <stdbool.h>

// Function prototype
// @Time Complexity O(n/2)
// @Space Complexity O(1)
void reverseString(char* s, int sSize)
{
    int i= 0;
    int j= sSize-1;

    while(i<j)
    {
        printf("Indise while");
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

}

int main() {
    char test1[] = "hello";
    int size1 = sizeof(test1) - 1; // subtracting 1 for the null terminator
    reverseString(test1, size1);
    printf("Test 1: %s\n", test1);  // Should print "olleh"

    char test2[] = "Hannah";
    int size2 = sizeof(test2) - 1; // subtracting 1 for the null terminator
    reverseString(test2, size2);
    printf("Test 2: %s\n", test2);  // Should print "hannaH"

    return 0;
}
