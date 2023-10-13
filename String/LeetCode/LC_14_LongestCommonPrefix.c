#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function prototype for longestCommonPrefix
// @Note : My Ugly Approach
// @Time Complexity : 
// @Space Complexity :
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int length1 = strlen(strs[0]);
    int length2 = strlen(strs[1]);
    int length3 = strlen(strs[2]);

    int shortest_len = 0;
    if(length1 < length2)
    {
        shortest_len = length1;
    }else if (length2 < length3)
    {
        shortest_len = length2;
    }else 
    {
        shortest_len = length3;
    }

    printf("Shortest length = %d\n", shortest_len);
    int flag = 0;
    char * returnStr = (char *)malloc(shortest_len*sizeof(char));
    for(int i=0;i<shortest_len;i++)
    {
        if (strs[0][i] == strs[1][i] == strs[2][i])
        {
            flag = 1;
            *returnStr = strs[0][i];
        }
    }
    if (flag == 0)
    {
        returnStr = "";
    }
    return returnStr;
}

int main() {
    // Test 1
    int strsSize1 = 3;
    char *strs1[] = {"flower", "flow", "flight"};
    char *result1 = longestCommonPrefix(strs1, strsSize1);
    printf("Test 1 result: %s\n", result1); // Expected: "fl"
    free(result1);  // If you are allocating memory in longestCommonPrefix

    // Test 2
    int strsSize2 = 3;
    char *strs2[] = {"dog", "racecar", "car"};
    char *result2 = longestCommonPrefix(strs2, strsSize2);
    printf("Test 2 result: %s\n", result2); // Expected: ""
    free(result2);  // If you are allocating memory in longestCommonPrefix

    return 0;
}
