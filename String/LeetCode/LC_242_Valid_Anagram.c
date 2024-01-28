#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* 
// @ Note : My Ugly Approach
// Time Complexity : O(s + t)
// Space Complexity : O(s + t)
// one approach ot improve was to use same freuency distribution ++ in first -- in second
bool isAnagram(char* s, char* t) {
    // create a character frequency distribution
    int frequency1[62] = {0}; // 26 + 26 + 10
    int frequency2[62] = {0};

    // Traverse first string
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            // so index 0 to 9 in frequency
            int index = (int)(s[i] - '0');
            frequency1[index]++; 

        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            // so index 10 to 35
            int index = s[i] - 'a' + 10;
            frequency1[index]++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            // so index 35 to 62
            int index = s[i] - 'A' + 10;
            frequency1[index]++;
        }
    }

    // Traverse second string
    // Traverse first string
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] >= '0' && t[i] <= '9')
        {
            // so index 0 to 9 in frequency
            int index = (int)(t[i] - '0');
            frequency2[index]++; 

        }
        else if (t[i] >= 'a' && t[i] <= 'z')
        {
            // so index 10 to 35
            int index = t[i] - 'a' + 10;
            frequency2[index]++;
        }
        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            // so index 35 to 62
            int index = t[i] - 'A' + 10;
            frequency2[index]++;
        }
    }

    // Check if two frequencies are same
    for(int i=0;i<62;i++)
    {
        if(frequency1[i] != frequency2[i])
        {
            return false;
            break;
        }
    }
    return true;

} */
int compfunc(void * a, void * b)
{
    return (*(char *)a - *(char *)b );
}
bool isAnagram(char* s, char* t) {
    // sort the arrays using q sort
    qsort(s, strlen(s), sizeof(char), compfunc);
    qsort(t, strlen(t), sizeof(char), compfunc);

    // compare two sorted strings
    int longest_string =  (strlen(s) >= strlen(t)) ?strlen(s) :strlen(t) ;

    for (int i = 0; i< longest_string; i++)
    {
        if (s[i] == t[i])
        {

        }else{
            return false;
        }
    }
    return true;
}

int main() {
    char test1_s[] = "anagram";
    char test1_t[] = "nagaram";
    printf("Test 1: %s\n", isAnagram(test1_s, test1_t) ? "true" : "false");  // Should print true

    char test2_s[] = "rat";
    char test2_t[] = "car";
    printf("Test 2: %s\n", isAnagram(test2_s, test2_t) ? "true" : "false");  // Should print false

    char test3_s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char test3_t[] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba";
    printf("Test 3: %s\n", isAnagram(test3_s, test3_t) ? "true" : "false");  // Should print false

    return 0;
}