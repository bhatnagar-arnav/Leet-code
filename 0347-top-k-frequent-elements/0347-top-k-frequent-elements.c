#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100003

typedef struct {
    int key;
    int freq;
    int used;
} HashEntry;

HashEntry table[HASH_SIZE];

// Hash map: count frequency of each number
void countFreq(int* nums, int n) {
    memset(table, 0, sizeof(table));
    for (int i = 0; i < n; i++) {
        int idx = ((unsigned int)nums[i] * 2654435761u) % HASH_SIZE;
        while (table[idx].used && table[idx].key != nums[i])
            idx = (idx + 1) % HASH_SIZE;
        if (!table[idx].used) {
            table[idx].key = nums[i];
            table[idx].freq = 0;
            table[idx].used = 1;
        }
        table[idx].freq++;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    countFreq(nums, numsSize);

    // Bucket sort: buckets[i] holds elements with frequency i
    // Max frequency can be numsSize
    int** buckets = (int**)calloc(numsSize + 1, sizeof(int*));
    int*  bCount  = (int*)calloc(numsSize + 1, sizeof(int));

    // Count how many elements go in each bucket
    for (int i = 0; i < HASH_SIZE; i++) {
        if (table[i].used)
            bCount[table[i].freq]++;
    }

    // Allocate each bucket
    for (int i = 1; i <= numsSize; i++) {
        if (bCount[i] > 0) {
            buckets[i] = (int*)malloc(bCount[i] * sizeof(int));
            bCount[i] = 0; // reset to use as insertion index
        }
    }

    // Fill buckets
    for (int i = 0; i < HASH_SIZE; i++) {
        if (table[i].used) {
            int f = table[i].freq;
            buckets[f][bCount[f]++] = table[i].key;
        }
    }

    // Collect top-k from highest frequency buckets
    int* result = (int*)malloc(k * sizeof(int));
    int  count  = 0;
    for (int f = numsSize; f >= 1 && count < k; f--) {
        for (int j = 0; j < bCount[f] && count < k; j++)
            result[count++] = buckets[f][j];
    }

    // Cleanup
    for (int i = 1; i <= numsSize; i++)
        if (buckets[i]) free(buckets[i]);
    free(buckets);
    free(bCount);

    *returnSize = k;
    return result;
}