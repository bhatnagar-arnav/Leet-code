int numSpecial(int** mat, int matSize, int* matColSize) {
    int m=matSize;
    int n=*matColSize;
    int rowSum[m], colSum[n];
    for (int i = 0; i < m; i++) rowSum[i] = 0;
    for (int j = 0; j < n; j++) colSum[j] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rowSum[i] += mat[i][j];
            colSum[j] += mat[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                count++;
            }
        }
    }

    return count;
}