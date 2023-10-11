#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration
char * decodeMessage(char * key, char * message);

// The main function
int main() {
    char key[] = "the quick brown fox jumps over the lazy dog";
    char message[] = "vkbs bs t suepuv";
    
    char *decodedMessage = decodeMessage(key, message);
    
    printf("Decoded Message: %s\n", decodedMessage);

    // Cleanup
    free(decodedMessage);  // assuming decodeMessage() dynamically allocates memory for the output string.

    return 0;
}

char * decodeMessage(char * key, char * message){
     char substitutionTable[][26] = {
        {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'},
        {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}
    };
    char new_key[26]= {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    int app[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int j = 0;
    for(int i = 0; i < strlen(key) && j < 26; i++){
        if(key[i] != ' ' && app[key[i] - 'a'] == 0){
            new_key[j++] = key[i];
            app[key[i] - 'a'] = 1;
        }
    }
    printf("NEW KEY \n");
    for(int i = 0; i < j; i++){
        printf("%c", new_key[i]);
    }
    printf("\n");
    printf("Updating table \n");
    for(int i = 0; i < 26; i++){
        substitutionTable[0][i] = new_key[i];
    }
    printf("\n");
    printf("NEW TABLE \n");
    for(int i = 0; i < 26; i++){
        printf("%c", substitutionTable[0][i]);
    }
    printf("\n");
    for(int i = 0; i < 26; i++){
        printf("%c", substitutionTable[1][i]);
    }
    printf("\n");

    // traverse message
    char * returnArr = (char *) malloc(sizeof(char) *strlen(message)+1); 

    for(int i=0;i<strlen(message);i++)
    {
        if(message[i] == ' ' )
        {
            printf(" ");
            continue;
        }
        int index = message[i] - 'a';
        //printf("%c", message[i]);
        //returnArr[i] = substitutionTable[0][];
    }
    printf("\n");

    return returnArr;

    /* for(int i=0; i< strlen(new_key); i++)
    {

        printf("%c",key[i]);
        printf("%d",key[i] - 'a' );
        app[key[i] - 'a'] += 1;

        if(app[key[i] - 'a'] == 1)
        {
            substitutionTable[0][i] = key[i];
        }
        else{
            printf("\nDuplicate key %c\n",key[i]);
        }
        // substitutionTable[0][i] = key[i];
    }
    printf("\n\n");
    for(int i=0;i<26;i++)
    {
        //printf("%c",substitutionTable[0][i]);
        printf("%d",app[i]);
    }
    printf("\n\n----------------------------------------------------------------\n");
    printf("\n\n");

    for(int i=0;i<26;i++)
    {
        printf("%c",substitutionTable[0][i]);
        //printf("%d",app[i]);
    }
    printf("\n");

    for(int i=0;i<26;i++)
    {
        printf("%c",substitutionTable[1][i]);
        //printf("%d",app[i]);
    }
    printf("\n----------------------------------------------------------------\n"); */

    // traverse 


}
