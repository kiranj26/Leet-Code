#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* // Function prototype for longestCommonPrefix
// @Note : My Ugly Approach
// @Time Complexity : O(n*m)
// @Space Complexity : O(n)
char * longestCommonPrefix(char ** strs, int strsSize){
     // if strSize is 0 return ""
    if (strsSize == 0) return "";
    // find the shortest substring from string
    int shortest_len = strlen(strs[0]);

    for(int i = 0; i<strsSize; i++)
    {
        int len = strlen(strs[i]);
        if (len < shortest_len)
        {
            shortest_len = len;
        }
    }
    printf("Shortest length = %d\n", shortest_len);

    // create return array
    char * returnStr = (char *) malloc ((shortest_len+1)* sizeof(char));
    char * ret = returnStr;

    // Traverse eah sub string
    for (int i=0;i<shortest_len;i++)
    {
        int all_match = 0;
        char c = strs[0][i];
        // hceck in all strings
        for(int j=0; j<strsSize;j++)
        {
            if (strs[j][i] == c)
            {
               all_match = 1;
            }else
            {
                all_match = 0;
                break;
            }
        }
        if (all_match == 1)
        {
            *returnStr++ = c;
        }else
        {
            break;
        }

    }
    *returnStr = '\0';
    return ret;
} */



// @NOte : Online Approach (Methode Name : )

char * longestCommonPrefix(char ** strs, int strsSize){
    int cntCommonPrefix = 0;
    int firstStrSize  = strlen(strs[0]);

    for (int i = 0 ; i < firstStrSize; i++)
    {
        for (int s  = 1; s < strsSize ; s++)
        {
            if (strs[0][i] != strs[s][i])
            {
                // load null and return 
                strs[0][cntCommonPrefix] = '\0';
                return strs[0];
            }
        }
        cntCommonPrefix++;
    }
    return strs[0];
}

int main() {
    // Test 1
    int strsSize1 = 3;
    char *strs1[] = {"flower", "flow", "flight"};
    char *result1 = longestCommonPrefix(strs1, strsSize1);
    printf("Test 1 result: %s\n", result1); // Expected: "fl"
    //free(result1);  // If you are allocating memory in longestCommonPrefix

    // Test 2
    int strsSize2 = 3;
    char *strs2[] = {"dog", "racecar", "car"};
    char *result2 = longestCommonPrefix(strs2, strsSize2);
    printf("Test 2 result: %s\n", result2); // Expected: ""
    //free(result2);  // If you are allocating memory in longestCommonPrefix

    return 0;
}
