#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Brute Force Approach */
bool isIsomorphic(char* s, char* t) {
    int smap[256] = {0}; // Use int to store -1
    int tmap[256] = {0};

    // Initialize mapping arrays
    memset(smap, -1, sizeof(smap));
    memset(tmap, -1, sizeof(tmap));

    for (int i = 0; s[i]; i++) {
        unsigned char sc = s[i];
        unsigned char tc = t[i];

        // Check if mapping exists and matches
        if ((smap[sc] != -1 && smap[sc] != tc) ||
            (tmap[tc] != -1 && tmap[tc] != sc)) {
            return false;
        }

        // Establish new mapping
        smap[sc] = tc;
        tmap[tc] = sc;
    }
    return true;
}

int main() {
    // Test cases
    printf("Test 1: %s\n", isIsomorphic("egg", "add") ? "true" : "false"); // Expected output: true
    printf("Test 2: %s\n", isIsomorphic("foo", "bar") ? "true" : "false"); // Expected output: false
    printf("Test 3: %s\n", isIsomorphic("paper", "title") ? "true" : "false"); // Expected output: true

    return 0;
}
