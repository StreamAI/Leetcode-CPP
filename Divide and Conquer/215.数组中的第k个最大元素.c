/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

void swap(int* a, int* b){
    if(*a != *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int divided(int* nums, int left, int right){
    int mid = left + (right - left)/2;
    if(nums[left] < nums[mid])
        swap(&nums[left], &nums[mid]);
    if(nums[left] < nums[right])
        swap(&nums[left], &nums[right]);
    if(nums[mid] < nums[right])
        swap(&nums[mid], &nums[right]);
    
    int pivot = right - 1;
    swap(&nums[mid], &nums[pivot]);

    int i = left, j = pivot;
    while (1)
    {
        while (i < pivot && nums[i] > nums[pivot])
            i++;
        while (j > left && nums[j] <= nums[pivot])
            j--;
        
        if(i < j)
            swap(&nums[i], &nums[j]);
        else
            break;
    }

    swap(&nums[i], &nums[pivot]);

    return i;
}

int findKthLargest(int* nums, int numsSize, int k){
    int left = 0, right = numsSize - 1;
    
    while (1)
    {
        if(right - left <= 1){
            if(right - left == 1 && nums[left] < nums[right])
                swap(&nums[left], &nums[right]);
            if(left == k - 1)
                return nums[left];
            else if(right == k - 1)
                return nums[right];
        }
        
        int mid = divided(nums, left, right);
        if(mid == k - 1)
            return nums[mid];
        else if(mid < k - 1)
            left = mid + 1;
        else if(mid > k - 1)
            right = mid - 1;
    }
}
// @lc code=end

