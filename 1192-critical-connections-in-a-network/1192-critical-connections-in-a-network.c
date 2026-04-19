#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int *data;
    int size;
    int cap;
} Vec;

Vec* newVec() {
    Vec* v = (Vec*)malloc(sizeof(Vec));
    v->size = 0;
    v->cap = 2;
    v->data = (int*)malloc(v->cap * sizeof(int));
    return v;
}

void push(Vec* v, int x) {
    if (v->size == v->cap) {
        v->cap *= 2;
        v->data = (int*)realloc(v->data, v->cap * sizeof(int));
    }
    v->data[v->size++] = x;
}

int timeCounter;
int *disc, *low;
int **res, resSize;

void dfs(int u, int parent, Vec** adj) {
    disc[u] = low[u] = ++timeCounter;
    for (int i = 0; i < adj[u]->size; i++) {
        int v = adj[u]->data[i];
        if (v == parent) continue;
        if (!disc[v]) {
            dfs(v, u, adj);
            low[u] = low[u] < low[v] ? low[u] : low[v];
            if (low[v] > disc[u]) {
                res[resSize] = (int*)malloc(2 * sizeof(int));
                res[resSize][0] = u;
                res[resSize][1] = v;
                resSize++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : low[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    disc = (int*)calloc(n, sizeof(int));
    low = (int*)calloc(n, sizeof(int));
    Vec** adj = (Vec**)malloc(n * sizeof(Vec*));
    for (int i = 0; i < n; i++) adj[i] = newVec();

    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0], b = connections[i][1];
        push(adj[a], b);
        push(adj[b], a);
    }

    res = (int**)malloc(connectionsSize * sizeof(int*));
    resSize = 0;
    timeCounter = 0;

    dfs(0, -1, adj);

    *returnSize = resSize;
    *returnColumnSizes = (int*)malloc(resSize * sizeof(int));
    for (int i = 0; i < resSize; i++) (*returnColumnSizes)[i] = 2;

    return res;
}
