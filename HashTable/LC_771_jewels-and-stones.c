#include <stdio.h>
#include <string.h>

/* Brute Force Approach
   - Compares each character in 'jewels' with each character in 'stones'.
   - Time Complexity: O(J*S), where J is the length of 'jewels' and S is the length of 'stones'.
     This is because it uses two nested loops; the outer loop runs for each character in 'jewels' 
     and the inner loop runs for each character in 'stones'.
   - Space Complexity: O(1), as it uses only a fixed number of integer variables and does not 
     allocate any additional space that depends on the input size.
*/
/* 
int numJewelsInStones(char * jewels, char * stones) {
    int jewelLen = strlen(jewels);
    int stoneLen = strlen(stones);
    int count  = 0 ;

    for (int  i =0 ;i < jewelLen ; i++) {
        for (int j = 0; j < stoneLen ; j ++) {
            if (jewels[i] == stones[j]) {
                count++;
            }
        }
    }
    return count;
}
*/

/* Using Hash Table
   - Counts the frequency of each character in 'jewels' and 'stones' using two hash tables.
   - Then, calculates the total count by multiplying frequencies of matching characters in both tables.
   - Time Complexity: O(J + S), where J is the length of 'jewels' and S is the length of 'stones'.
     This is because it iterates separately over 'jewels' and 'stones' to populate the hash tables, 
     and then iterates over the hash table once.
   - Space Complexity: O(1), as the size of the hash tables (52) is constant and does not depend 
     on the size of the input.
*/
int numJewelsInStones(char * jewels, char * stones) {
    int jewelLen = strlen(jewels);
    int stoneLen = strlen(stones);

    int jewelFreq[52] = {0}; // Hash table for frequency of each character in 'jewels'
    int stoneFreq[52] = {0}; // Hash table for frequency of each character in 'stones'

    // Loading frequencies of characters in 'jewels'
    for (int i = 0 ; i < jewelLen; i++) {
        if (jewels[i] >= 'a' && jewels[i] <= 'z') {
            jewelFreq[jewels[i] - 'a']++;
        }
        if (jewels[i] >= 'A' && jewels[i] <= 'Z') {
            jewelFreq[jewels[i] - 'A' + 26]++;
        }
    }

    // Loading frequencies of characters in 'stones'
    for (int i = 0 ; i < stoneLen; i++) {
        if (stones[i] >= 'a' && stones[i] <= 'z') {
            stoneFreq[stones[i] - 'a']++;
        }
        if (stones[i] >= 'A' && stones[i] <= 'Z') {
            stoneFreq[stones[i] - 'A' + 26]++;
        }
    }
    
    // Calculating total count of jewels in stones
    int count = 0;
    for (int i = 0 ; i < 52; i++) {
        count += (stoneFreq[i] * jewelFreq[i]);
    }

    return count;
}

int main() {
    char jewels1[] = "aA";
    char stones1[] = "aAAbbbb";
    printf("\nNumber of jewels in stones (aA, aAAbbbb): %d\n", numJewelsInStones(jewels1, stones1));

    char jewels2[] = "z";
    char stones2[] = "ZZ";
    printf("\nNumber of jewels in stones (z, ZZ): %d\n", numJewelsInStones(jewels2, stones2));

    return 0;
}
