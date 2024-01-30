#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/* Approach and Complexity Analysis
   - This function decodes a message based on a substitution cipher provided by the 'key'.
   - The approach involves two main steps:
     1. Constructing a mapping from each character in the key to the alphabet letters in order.
     2. Decoding the message using this mapping.
   - Time Complexity: O(N + M), where N is the length of the key and M is the length of the message.
     The first loop iterates over the key to build the map, and the second loop iterates over the message to decode it.
   - Space Complexity: O(1), as the space used for the map and the used array is constant and does not depend on the input size.
*/
char * decodeMessage(char * key, char * message) {
    // construct a map where each characters from the key is mapped to incrementing assignments
    char map[26] = {0};
    bool used[26] = {0};

    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] != ' ' && !used[key[i] - 'a']) {
            map[key[i] - 'a'] = 'a' + mapIndex;
            used[key[i] - 'a'] = true;
            mapIndex++;
        }
    }

    // decoding the message
    for(int i = 0; message[i ]!= '\0'; i++)
    {
        if (message[i] != ' ')
        {
            message[i] = map[message[i] - 'a'];
        }
    }
    return message;
}
/* Hash Map Approach */

int main() {
    char key1[] = "the quick brown fox jumps over the lazy dog";
    char message1[] = "vkbs bs t suepuv";
    printf("Decoded message: %s\n", decodeMessage(key1, message1));

    char key2[] = "eljuxhpwnyrdgtqkviszcfmabo";
    char message2[] = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    printf("Decoded message: %s\n", decodeMessage(key2, message2));

    return 0;
}
