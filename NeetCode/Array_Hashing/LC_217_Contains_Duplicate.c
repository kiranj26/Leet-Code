#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// /* Brute Force Approach */
/* bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0 ; i < numsSize ; i++) {
        for (int j = 0 ; j < nums[i] ; j++) {
            if (i == j) continue;
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
} */
/* Optimized 1 : 
   - Sort the array and just check if adjent eements are same 
*/
/* int cmp (const void * a , const void * b)
{
    return ( *(int *)a - *(int * )b );
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp); 
    for (int i = 1 ; i < numsSize; i++)
    {
        if (nums[i] == nums[i-1])
        {
            return true;
        }
    }
    return false;
} */
/* Optimized 2 : Hash Map
   - 
*/
typedef struct {
	int key;
	UT_hash_handle hh; // Makes this structure hashable
} hash_table;

hash_table *hash = NULL, *elem, *tmp;
bool containsDuplicate(int* nums, int numsSize){
    if (numsSize == 1) {
      return false;
    }
    
    bool flag = false;
    
    for (int i=0; i<numsSize; i++) {
        HASH_FIND_INT(hash, &nums[i], elem);
        
        if(!elem) {
           elem = malloc(sizeof(hash_table));
           elem->key = nums[i];
           HASH_ADD_INT(hash, key, elem);
            
           flag = false;
       }
       else {
           flag = true;
           break;
       }
    }
                          
    // Free up the hash table 
	HASH_ITER(hh, hash, elem, tmp) {
		HASH_DEL(hash, elem); free(elem);
	}
    
    return flag;
}
int main() {
    int nums1[] = {1, 2, 3, 1};
    int nums2[] = {1, 2, 3, 4};
    int nums3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    printf("Contains duplicate in nums1? %s\n", containsDuplicate(nums1, 4) ? "Yes" : "No");
    printf("Contains duplicate in nums2? %s\n", containsDuplicate(nums2, 4) ? "Yes" : "No");
    printf("Contains duplicate in nums3? %s\n", containsDuplicate(nums3, 10) ? "Yes" : "No");

    return 0;
}
