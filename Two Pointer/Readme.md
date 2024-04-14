# Educative.io
# Notes

# Overview : 
- Uses two pointers to iterate over an array or list until the conditions of the problem are satisfied    
- **Whenever there is a requirement to find two elements in a list or anything that satisfies the certain condition , two pointer should be the solution**    
- **Example Questions  : Palindrome**    

# Does my problem match this pattern?
## Yes, 
if all of these conditions are fulfilled:    
- The input data can be traversed in a linear fashion, that is, it’s in an array, in a linked list, or in a string of characters.    

- We limit our focus to a specific range of elements within the input data, as dictated by the positions of the two pointers, allowing us to consider a small subset of elements rather than the entire set.    

## No.
No, if either of these conditions is fulfilled:
- The input data cannot be traversed in a linear fashion, that is, it’s neither in an array, nor in a linked list, nor in a string of characters.    
- The problem requires an exhaustive search of the solution space, that is, eliminating one solution does not eliminate any others.    

## Match the problems that can be solved

1. *Check if a string is a palindrome*. 
(Yes, By utilizing two pointers, one starting from the beginning of the string and the other from the end, we can compare the corresponding characters. If the characters match at each step, we continue moving the pointers inward until the pointers cross each other.)    

2. *Find any three values in a sorted array that sum up to N*    
(Yes, By iterating through the array and considering each value, we calculate the sum of the current value and the other two values. To find the other two values, we can utilize two pointers in each iteration: one starting from the leftmost element and the other from the rightmost element. Comparing this sum with 825, we increment or decrement the pointers accordingly.)    

3. *Find all permutations of the following set of elements, {z,y,z}*    
(No, Finding permutations requires generating all possible combinations, which involves exploring various branches of a decision tree. This process does not align with the linear traversal approach of the Two Pointers pattern, making it unsuitable for solving permutation problems.)    

4. *Generate a string of n balanced parentheses*    
(No, Generating a string of balanced parentheses requires a different approach, such as backtracking, since it involves forming a specific pattern with nested parentheses. This kind of pattern generation is not supported by the Two Pointers pattern.)        

# Valid Palindrome 
**A palindrome is a word, phrase, or sequence of characters that reads the same backward as forward.**    

Examples 
- abba
- abcca
- racecar

## Logic 
1. Initialism two pointers     
2. Check if the values at two pointers are identical
3. If not identical return FALSE else increment left and decrement right pointer
4. Keep traversing till we reach middle L==R
5. If we reach middle without finding mismatch return TRUE    

## Solution C

```
bool isAlphanumeric(char ch)
{
    if (((ch>='0')&&(ch<='9')) || 
    ((ch>='a')&&(ch<='z')) || 
    ((ch>='A')&&(ch<='Z')) )
    {
        return true;
    }else{
        return false;
    }
}
bool isPalindrome(char *s) {
    char * L = &s[0];
    char * R = &s[strlen(s)-1];
    // while address of L is less than address of R
    while(L <= R)
    {
        // chek =ck for alphanumeric
        if (!isAlphanumeric(*L))
        {
            L++;
            continue;
        }
        if(!isAlphanumeric(*R))
        {
            R--;
            continue;
        }

        if( tolower(*L) == tolower(*R) ){
            // do nothing
        }else{
            return false;
        }
        L++;
        R--;
    }

    return true;
}
```

# Sum of Three Values



