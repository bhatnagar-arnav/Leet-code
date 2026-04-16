
bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) color[i] = 0;

    int* queue = (int*)malloc(graphSize * sizeof(int));

    for (int start = 0; start < graphSize; start++) {
        if (color[start] != 0) continue;
        int front = 0, rear = 0;
        queue[rear++] = start;
        color[start] = 1;

        while (front < rear) {
            int u = queue[front++];
            for (int i = 0; i < graphColSize[u]; i++) {
                int v = graph[u][i];
                if (color[v] == 0) {
                    color[v] = -color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    free(color);
                    free(queue);
                    return false;
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}
