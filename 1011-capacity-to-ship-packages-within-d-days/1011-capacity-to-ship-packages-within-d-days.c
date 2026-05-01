#include <stdio.h>

int canShip(int* weights, int n, int days, int cap) {
    int d = 1, load = 0;
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            d++;
            load = 0;
        }
        load += weights[i];
    }
    return d <= days;
}

int shipWithinDays(int* weights, int n, int days) {
    int lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        if (weights[i] > lo) lo = weights[i];
        hi += weights[i];
    }

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canShip(weights, n, days, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
