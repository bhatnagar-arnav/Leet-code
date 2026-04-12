
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int** adj = (int**)malloc((n+1) * sizeof(int*));
    int* adjSize = (int*)calloc(n+1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(timesSize * 2 * sizeof(int));
    }
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0], v = times[i][1], w = times[i][2];
        adj[u][adjSize[u]++] = v;
        adj[u][adjSize[u]++] = w;
    }

    int* dist = (int*)malloc((n+1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[k] = 0;

    bool* visited = (bool*)calloc(n+1, sizeof(bool));

    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (u == -1 || dist[u] == INT_MAX) break;
        visited[u] = true;
        for (int j = 0; j < adjSize[u]; j += 2) {
            int v = adj[u][j], w = adj[u][j+1];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            ans = -1;
            break;
        }
        if (dist[i] > ans) ans = dist[i];
    }

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj);
    free(adjSize);
    free(dist);
    free(visited);

    return ans;
}