bool visited[1005];

void dfs(int** rooms, int* roomsColSize, int i, int n) {
    visited[i] = true;
    for (int j = 0; j < roomsColSize[i]; j++) {
        int key = rooms[i][j];
        if (!visited[key]) dfs(rooms, roomsColSize, key, n);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    for (int i = 0; i < roomsSize; i++) visited[i] = false;
    dfs(rooms, roomsColSize, 0, roomsSize);
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }
    return true;
}