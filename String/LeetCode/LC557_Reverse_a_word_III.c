#include <stdio.h>
#include <string.h>

// Function prototype
char* reverseWords(char* s);

int main() {
    // Example test cases
    char input1[] = "Let's take LeetCode contest";
    char input2[] = "Mr Ding";

    // Call reverseWords function and print the result
    printf("Original: %s\nReversed: %s\n\n", input1, reverseWords(input1));
    printf("Original: %s\nReversed: %s\n", input2, reverseWords(input2));

    return 0;
}

// Ugly Approach : Self made
// Time Complexity :
// Space Complexity :
char* reverseWords(char* s) {
    printf("Input String: %s\n", s);
    
    // Placeholder for the main logic
    return s;
}
