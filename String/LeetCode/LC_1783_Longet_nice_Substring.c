#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isNice(char * s, int start, int end)
{
    int frequency_Upper[26] = {0};
    int frequency_Lower[26] = {0};

    for(int i=start; i<=end; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            frequency_Lower[s[i] - 'a']++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            frequency_Upper[s[i] - 'A']++;
        }
    }

    for(int i=0; i<26; i++)
    {
        if((frequency_Lower[i] > 0 && frequency_Upper[i] == 0) || (frequency_Lower[i] == 0 && frequency_Upper[i] > 0))
        {
            return 0;
        }
    }
    return 1;
}

char *longestNiceSubstring(char *s) {
    int start = 0;
    int end = 0;
    int len = strlen(s);

    int maxLen = 0;
    int maxStart = 0;
    int maxEnd = 0;

    while(end<len)
    {
        // move the end pointer
        end++;

        // check the window and see if the string is nice done by 
        // verufying if upperFrequency and Lower Frequency is not zero
        int nice = isNice(s,start,end);
        if (nice)
        {
            // window is nice
            // so increment window size
            end++;

            maxLen = (maxLen < ( end - start +1)) ? ( end - start +1) : maxLen;

            maxStart = start;
            maxEnd = end;
        }else{
            // window is not nice 
            // decrement the window size
            start ++;   
        }

    }
    //
    char * result = (char *)malloc(maxLen + 1 * sizeof(char));
    strncpy(result,s+maxStart,maxLen);
    result[maxLen] = '\0';
    return result;
}

int main() {
    // Test cases
    char *test1 = "YazaAay";
    char *test2 = "Bb";
    char *test3 = "c";

    printf("Test 1 - Input: %s, Output: %s\n", test1, longestNiceSubstring(test1));
    printf("Test 2 - Input: %s, Output: %s\n", test2, longestNiceSubstring(test2));
    printf("Test 3 - Input: %s, Output: %s\n", test3, longestNiceSubstring(test3));

    return 0;
}
