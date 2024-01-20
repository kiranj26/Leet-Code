#include <stdio.h>
#include <stdbool.h>

bool equalFrequency(char* word) {
    int no_of_letters_present_more_than_one = 0;
    // Keep an hash table of frequency of each letter
    int frequency[26] = {0};
    int len = strlen(word);

    // Create hash map of frequency of characters in word
    for(int i=0; i< len; i++) {
        frequency[word[i]- 'a']++;
        // also at any time when we are filling the frequency
        // if two letters appears twice, then return false
        if ((frequency[word[i]- 'a']) > 1)
        {
            no_of_letters_present_more_than_one ++;
        }
    }

    // printf("No of letters present more than one = %d\n", no_of_letters_present_more_than_one);
    if ((no_of_letters_present_more_than_one % 2) != 0)
    {
        return false;
    }else{
        return true;
    }
}
int main() {
    int word1 = "abcc";
    int result1 = equalFrequency(word1);
    printf("Result 1 = %d\n", result1);

    int word2 = "aazzz";
    int result2 = equalFrequency(word2);
    printf("Result 1 = %d\n", result1);


}
