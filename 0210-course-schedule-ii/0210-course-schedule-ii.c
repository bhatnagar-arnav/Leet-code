
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(prerequisitesSize * sizeof(int));
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0], b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }
    int* order = (int*)malloc(numCourses * sizeof(int));
    int count = 0;
    while (front < rear) {
        int course = queue[front++];
        order[count++] = course;
        for (int i = 0; i < adjSize[course]; i++) {
            int next = adj[course][i];
            indegree[next]--;
            if (indegree[next] == 0) queue[rear++] = next;
        }
    }
    free(indegree);
    free(adjSize);
    for (int i = 0; i < numCourses; i++) free(adj[i]);
    free(adj);
    free(queue);
    if (count == numCourses) {
        *returnSize = numCourses;
        return order;
    } else {
        *returnSize = 0;
        free(order);
        return NULL;
    }
}