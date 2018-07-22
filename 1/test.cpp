#include <iostream>
#include <stdio.h>

void swap(int nums[], int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

bool duplicate(int nums[], int length, int duplication[])
{
    if(nums == NULL || length <= 0)
    {
        return false;
    }
    for(int i = 0; i < length; i++)
    {
        while(nums[i] != i)
        {
            if(nums[i] == nums[nums[i]])
            {
                duplication[0] = nums[i];
                return true;
            }
            swap(nums, i, nums[i]);
        }
    }
    return false;
}

int main()
{
    int nums[] = {2,1,0,4,2,3};
    int duplication[] = {0};
    int length = sizeof(nums);
    if(duplicate(nums, length, duplication))
    {
        printf("重复的数字是：%d\n", duplication[0]);
    }
    return 0;

}
