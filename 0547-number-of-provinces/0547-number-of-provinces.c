
int visited[205];

void dfs(int** isConnected, int n, int i) {
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(isConnected, n, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int count = 0;
    for (int i = 0; i < isConnectedSize; i++) visited[i] = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (!visited[i]) {
            dfs(isConnected, isConnectedSize, i);
            count++;
        }
    }
    return count;
}