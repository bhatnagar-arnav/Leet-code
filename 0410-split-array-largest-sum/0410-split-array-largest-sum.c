int splitArray(int* nums, int numsSize, int k) {
    long left = 0, right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > left) left = nums[i];
        right += nums[i];
    }
    while (left < right) {
        long mid = (left + right) / 2;
        int count = 1;
        long curr = 0;
        for (int i = 0; i < numsSize; i++) {
            if (curr + nums[i] > mid) {
                count++;
                curr = 0;
            }
            curr += nums[i];
        }
        if (count <= k) right = mid;
        else left = mid + 1;
    }
    return (int)left;
}
