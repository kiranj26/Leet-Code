#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* // @Note : Brute Force Approach
// @ Time Complexity : 
// @ Space Complexity : 
char* sortSentence(char* s) {
    char* array_of_strings[9] = {NULL};  // Initialize all pointers to NULL
    int len = strlen(s);

    int word_start = 0;
    int word_end;
    int index;
    int total_count = 0;

    int space_count = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == ' ' || i == len - 1) {  // Check for space or the end of the string
            word_end = (s[i] == ' ') ? i - 2 : i - 1;
            index = s[word_end + 1] - '0' - 1;
            
            array_of_strings[index] = (char*)malloc(word_end - word_start + 2);
            strncpy(array_of_strings[index], &s[word_start], word_end - word_start + 1);
            array_of_strings[index][word_end - word_start + 1] = '\0';
            
            total_count += word_end - word_start + 1;  // Add only the word length

            if(s[i] == ' ') {
                space_count++;
                word_start = i + 1;
            }
        }
    }

    char * final_result =  (char *)malloc((total_count + space_count + 1) * sizeof(char)); 
    int cnt = 0;
    for(int i = 0; i < 9; i++) {
        if(array_of_strings[i] != NULL) {  
            if (cnt > 0) {  
                final_result[cnt] = ' ';
                cnt++;
            }
            strcpy(final_result + cnt, array_of_strings[i]);
            cnt = cnt + strlen(array_of_strings[i]);
            free(array_of_strings[i]);
        }
    }
    final_result[cnt] = '\0';

    return final_result;
} */


// @ Note  : Online Approach
char* sortSentence(char* s) {
    char * array_of_strings [8] = {NULL};
    int len = strlen(s);
    for(int i = 0; i<len;i++)
    {
        if (s[i] > '0' && s[i] > '9')
        {
            
        }
    }
}  

int main() {
    char s[] = "is2 sentence4 This1 a3";
    char* sorted_sentence = sortSentence(s);
    printf("%s\n", sorted_sentence);
    free(sorted_sentence);
    return 0;
}
