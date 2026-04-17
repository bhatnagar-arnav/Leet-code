// Definition for a Node.
// struct Node {
//     int val;
//     int numNeighbors;
//     struct Node** neighbors;
// };

#include <stdlib.h>
#include <stdbool.h>

struct Node* cloneGraph(struct Node* node) {
    if (!node) return NULL;

    // LeetCode constraint: up to 100 nodes, values are 1-indexed
    struct Node** visited = (struct Node**)calloc(101, sizeof(struct Node*));
    struct Node** queue = (struct Node**)malloc(101 * sizeof(struct Node*));
    int front = 0, rear = 0;

    // Create clone for the starting node
    struct Node* cloneStart = (struct Node*)malloc(sizeof(struct Node));
    cloneStart->val = node->val;
    cloneStart->numNeighbors = node->numNeighbors;
    cloneStart->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));
    visited[node->val] = cloneStart;

    queue[rear++] = node;

    while (front < rear) {
        struct Node* curr = queue[front++];
        struct Node* currClone = visited[curr->val];

        for (int i = 0; i < curr->numNeighbors; i++) {
            struct Node* neigh = curr->neighbors[i];
            if (!visited[neigh->val]) {
                struct Node* neighClone = (struct Node*)malloc(sizeof(struct Node));
                neighClone->val = neigh->val;
                neighClone->numNeighbors = neigh->numNeighbors;
                neighClone->neighbors = (struct Node**)malloc(neigh->numNeighbors * sizeof(struct Node*));
                visited[neigh->val] = neighClone;
                queue[rear++] = neigh;
            }
            currClone->neighbors[i] = visited[neigh->val];
        }
    }

    free(queue);
    return cloneStart;
}
