

char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int lowerlen = (len1<len2) ? len1: len2;
    int upperlen = (len1>len2) ? len1: len2 ;
    char * result = (char *)malloc(len1+len2+1 * sizeof(char));

    int word1index = 0;
    int word2index = 0;
    int i = 0;
    for (i = 0; i < lowerlen + upperlen ; i++)
    {
        // copy everything one by one if i is less than lower length
        if (i < (2 * lowerlen)){
            if (i%2 == 0)
            {
                result[i] = word1[word1index++];
            }else
            {
                result[i] = word2[word2index++];
            }
        }
        if (i >= (2 * lowerlen))
        {
            if (len2 > len1){
                result[i] = word2[word2index++];
            }else
            {
                result[i] = word1[word1index++];
            }              
        }
    }
    result[i] = '\0';

    return result;
}