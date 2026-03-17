typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;
typedef struct {
    MinHeap *heap;
    int k;
} KthLargest;
MinHeap* createHeap(int capacity) {
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->data[parent] > h->data[idx]) {
            swap(&h->data[parent], &h->data[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap *h, int idx) {
    while (2 * idx + 1 < h->size) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = left;

        if (right < h->size && h->data[right] < h->data[left])
            smallest = right;

        if (h->data[idx] > h->data[smallest]) {
            swap(&h->data[idx], &h->data[smallest]);
            idx = smallest;
        } else break;
    }
}

void heapPush(MinHeap *h, int val) {
    if (h->size < h->capacity) {
        h->data[h->size++] = val;
        heapifyUp(h, h->size - 1);
    } else if (val > h->data[0]) {
        h->data[0] = val;
        heapifyDown(h, 0);
    }
}

int heapTop(MinHeap *h) {
    return h->data[0];
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->heap = createHeap(k);

    for (int i = 0; i < numsSize; i++) {
        heapPush(obj->heap, nums[i]);
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    heapPush(obj->heap, val);
    return heapTop(obj->heap);
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap->data);
    free(obj->heap);
    free(obj);
}
