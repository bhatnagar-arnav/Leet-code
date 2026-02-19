int kadaneMax(int arr[], int n) {
    int maxSum = arr[0];
    int curSum = arr[0];
    for (int i = 1; i < n; i++) {
        curSum = (curSum + arr[i] > arr[i]) ? curSum + arr[i] : arr[i];
        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }
    return maxSum;
}
int kadaneMin(int arr[], int n) {
    int minSum = arr[0];
    int curSum = arr[0];
    for (int i = 1; i < n; i++) {
        curSum = (curSum + arr[i] < arr[i]) ? curSum + arr[i] : arr[i];
        if (curSum < minSum) {
            minSum = curSum;
        }
    }
    return minSum;
}

int maxSubarraySumCircular(int nums[], int n) {
    int normalMax = kadaneMax(nums, n);
    if (normalMax < 0) return normalMax;
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }
    int minSubarray = kadaneMin(nums, n);
    int circularMax = totalSum - minSubarray;

    return (normalMax > circularMax) ? normalMax : circularMax;
}

