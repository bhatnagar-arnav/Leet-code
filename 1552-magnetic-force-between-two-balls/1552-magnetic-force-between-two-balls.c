int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int canPlace(int* pos, int n, int m, int dist){
    int count = 1, last = pos[0];
    for(int i = 1; i < n; i++){
        if(pos[i] - last >= dist){
            count++;
            last = pos[i];
            if(count >= m) return 1;
        }
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m){
    qsort(position, positionSize, sizeof(int), cmp);
    int low = 1, high = position[positionSize-1] - position[0], ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(canPlace(position, positionSize, m, mid)){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
