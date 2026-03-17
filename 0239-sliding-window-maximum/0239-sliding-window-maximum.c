typedef struct {
    int *data;
    int front, rear, size, capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(sizeof(int) * capacity);
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    dq->capacity = capacity;
    return dq;
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

void pushBack(Deque* dq, int val) {
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->data[dq->rear] = val;
    dq->size++;
}

void popBack(Deque* dq) {
    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;
}

void popFront(Deque* dq) {
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
}

int front(Deque* dq) {
    return dq->data[dq->front];
}

int back(Deque* dq) {
    return dq->data[dq->rear];
}

// Sliding window maximum
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;

    Deque* dq = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
        // Remove indices out of window
        if (!isEmpty(dq) && front(dq) <= i - k) {
            popFront(dq);
        }

        // Maintain decreasing order in deque
        while (!isEmpty(dq) && nums[back(dq)] <= nums[i]) {
            popBack(dq);
        }

        pushBack(dq, i);

        // Record max for current window
        if (i >= k - 1) {
            result[*returnSize] = nums[front(dq)];
            (*returnSize)++;
        }
    }

    free(dq->data);
    free(dq);
    return result;
}