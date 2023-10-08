// Leet Code Problem 1816
// https://leetcode.com/problems/truncate-sentence/

// Initial __VERSION__
// 3 ms and 6.58 mb
char * truncateSentence(char * s, int k){
    char * p = s;
    int count = 0;
    char * returnString = (char *)malloc((strlen(s)*sizeof(char)) + 1);
    char * originalReturnString = returnString; // Preserve the starting address of the return string
    while(*p != '\0')
    {
        if (*p == ' ')
        {
            count ++;
        }
        if (count == k)
        {
            break;
        }
        *returnString = *p;
        p++;
        returnString++;
    }
    *returnString = '\0';
    
    return originalReturnString;
}

// Optamised __VERSION__
// 0 ms and 6.61 MB

char * truncateSentence(char * s, int k){
    char * p = s;
    int count = 0;

    while(*p != '\0')
    {
        if (*p == ' ')
        {
            count ++;
            if (count == k)
            {
                *p = '\0';  // Modify the original string in place
                break;
            }
        }
        p++;
    }

    return s;
}


// Explaination of optamisation
// Time Complexity can be optamised
// whatever we have we have to iterate over string s
// O(n)

// we can significantly reduce the space complexity as we can use the 
// point p created initially itself rather than using new memory to return trancated string
// See the code
// It changes space complexity from o(n) to o(1)

// FASTEST VERSION (0 ms)
// Already the fastest 
// Most Memory Efficient (5.7 MB)
char * truncateSentence(char * s, int k){
    int sp=0;
    
    for(int i=0;s[i]!='\0';i++){
        char ch=s[i];
        if(ch==' ')
        sp++;

        if(sp==k){
            s[i]='\0';
            return s;
        }
    }
    return s;
}


