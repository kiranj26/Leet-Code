

int singleNumber(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i < numsSize;i++)
    {
        result = nums[i] ^ result;
    }
    return result;
}
int main(int argc, char** argv)
{

    int nums [] = {2,2,1};

    printf("Result = %d\n", singleNumber(nums, sizeof(nums)));
}