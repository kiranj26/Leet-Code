// Brute Force
// Time Complexity : O(n^2)
// Space Complexity : O(1)

bool containsDuplicate(int* nums, int numsSize) {
    int i = 0;
    int j =0;

    for(i =0 ; i< numsSize; i++)
    {
        for (j = 0; j <numsSize; j++)
        {
            if (i == j)
            {
                continue;
            }
            // if same retyrn false
            if (nums[i] == nums[j])
            {
                printf("Value %d and %d is same\n", nums[i], nums[j]);
                return true;
            }
        }
    }
    // else retrn true
    return false;
}

// Optamised Approach : Using Soritng and One Loop
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
bool containsDuplicate(int* nums, int numsSize) {
    // lets sort the array
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    // now lets check every adjescent element maybe start i - 0 and j.= 1
    // till j reaches numsSize
    for(int i = 0, j = 1; j<numsSize;i++,j++)
    {
        if(nums[i] == nums[j])
        {
            return true;
        }
    }
return false;

}