#include <iostream>
#include <algorithm> // For std::sort
#include <string>    // For std::string
#include <unordered_map>

// Function to check if two strings are anagrams using C++ std::string
// bool isAnagram(std::string s, std::string t) {
//     if (s.size() != t.size()) return false;
//     std::sort(s.begin(), s.end());
//     std::sort(t.begin(), t.end());

//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] != t[i]) return false;
//     }
//     return true;
// }

/* Using Map*/
bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::unordered_map<char, int> smap;
    std::unordered_map<char, int> tmap;
    for (int i = 0 ; i < t.size(); i++) {
        smap[s[i]]++;
        tmap[t[i]]++;
    }
    for (int i = 0 ; i < smap.size(); i++) {
        if (smap[i] != tmap[i]) return false;
    }
    // fill the map
    return true;
}

int main() {
    std::string test1_s = "anagram";
    std::string test1_t = "nagaram";
    std::cout << "Test 1: " << (isAnagram(test1_s, test1_t) ? "true" : "false") << std::endl;

    std::string test2_s = "rat";
    std::string test2_t = "car";
    std::cout << "Test 2: " << (isAnagram(test2_s, test2_t) ? "true" : "false") << std::endl;

    std::string test3_s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::string test3_t = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba";
    std::cout << "Test 3: " << (isAnagram(test3_s, test3_t) ? "true" : "false") << std::endl;

    return 0;
}
