// Leet Code Problem 1773
// https://leetcode.com/problems/count-items-matching-a-rule/description/

// Initial __VERSION__
int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int count = 0;
    for (int i=0;i<itemsSize;i++)
    {
        if(strcmp(ruleKey, "type") == 0)
        {
            if (strcmp(ruleValue, items[i][0]) == 0)
            {
                count++;
            }
        }   
        if(strcmp(ruleKey, "color") == 0)
        {
            if (strcmp(ruleValue, items[i][1]) == 0)
            {
                count++;
            }
        }
        if(strcmp(ruleKey, "name") == 0)
        {
            if (strcmp(ruleValue, items[i][2]) == 0)
            {
                count++;
            }
        } 
    }
return count;

}

// Optamised __VERSION__
// We can remove the redandant checks we have implemented for ruleKey
int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int count = 0;
    int column = 0;  // We'll determine the right column before the loop
    
    if (strcmp(ruleKey, "type") == 0) {
        column = 0;
    } 
    else if (strcmp(ruleKey, "color") == 0) {
        column = 1;
    } 
    else if (strcmp(ruleKey, "name") == 0) {
        column = 2;
    }

    for (int i = 0; i < itemsSize; i++) {
        if (strcmp(ruleValue, items[i][column]) == 0) {
            count++;
        }
    }

    return count;
}
// Previous Time Complexity was O(n*m) n being no of items m being no of keys three in this case
// Time complexity of O(n) because you are only checking rule key once

// both version have space complexity of O(1) meaning space doesnt grow with time

// FASTEST VERSION (45 ms)
#include <string.h> // for strcmp()

#define TYPE  0
#define COLOR 1
#define NAME  2

int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int matches = 0;
    int i, c = 0;
    
    switch(ruleKey[0]) {
        case 't': c = TYPE; break;
        case 'c': c = COLOR; break;
        case 'n': c = NAME; break;
        default: return -1;
    }
    
    for(i=0; i<itemsSize; i++) {
        // order is: [0] -> type, [1] -> color, [2] -> name
        // `c' contains index offset
        if (strcmp(items[i][c], ruleValue) == 0) {
            matches++;
        }
        
    }
    
    return matches;
    
}

// Most Memory Efficient (13.4 MB)
int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int c = 0;
    int k;
    if(ruleKey[0]=='t')
        k = 0;
    else if(ruleKey[0]=='c')
        k = 1;
    else if(ruleKey[0]=='n')
        k = 2;
   
   
    for(int i =0; i < itemsSize; i++ ){
        if(strcmp(items[i][k],ruleValue) == 0){
            c++;
        }
    }
    return c;
}
