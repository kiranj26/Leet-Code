#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

/* brute force approach */
// bool containsDuplicate(std::vector<int>& nums) {
//     for(int i = 0 ; i < nums.size() ; i++) {
//         for (int j = 0 ; j < nums.size(); j++)
//         {
//             if (i == j) continue;
//             if (nums[i] == nums[j])
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

/* Using Sorting*/
// how to sort a vector using std::algorithms lirary
// std::sort(vect.start(), vector.end());
// bool containsDuplicate(std::vector<int>& nums) {
//     std::sort(nums.begin(), nums.end()); // sorting in asceding order
//     for (int i = 1 ; i < nums.size(); i ++)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             return true;
//         }
//     }
//     return false;
// }

/* Using UNordered Set */
// normal set is uniqueue and ordered
// unordered set have properties 
// - uniqieie
// - not ordered
// Use Case  : Go for set we need uniqueue and ordered and in unordered we dont need sorted set
// Search insertion and removal is O(1)
// uses hashing to insert into the buckets
// 
bool containsDuplicate(std::vector<int>& nums) {
    // create a unordered set
    std::unordered_set<int> s;

    for (int i = 0 ; i < nums.size() ; i++)
    {
        // find() return an iterator to the element if found and return false if not found
        // means if he has found element it will be not equel to end
        if (s.find(nums[i]) != s.end())
        {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    std::cout << "Contains duplicate in nums1? " << (containsDuplicate(nums1) ? "Yes" : "No") << std::endl;
    std::cout << "Contains duplicate in nums2? " << (containsDuplicate(nums2) ? "Yes" : "No") << std::endl;
    std::cout << "Contains duplicate in nums3? " << (containsDuplicate(nums3) ? "Yes" : "No") << std::endl;

    return 0;
}
