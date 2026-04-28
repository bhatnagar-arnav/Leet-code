int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) right = piles[i];
    }
    
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        long hours = 0; // use long to avoid overflow
        for (int i = 0; i < pilesSize; i++) {
            hours += (piles[i] + mid - 1) / mid; // ceil(piles[i]/mid)
        }
        
        if (hours <= h) {
            ans = mid;       // candidate speed
            right = mid - 1; // try smaller speed
        } else {
            left = mid + 1;  // need faster speed
        }
    }
    
    return ans;
}
