int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int** image, int m, int n, int i, int j, int oldColor, int newColor) {
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (image[i][j] != oldColor) return;
    image[i][j] = newColor;
    for (int d = 0; d < 4; d++) {
        dfs(image, m, n, i + dirs[d][0], j + dirs[d][1], oldColor, newColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldColor = image[sr][sc];
    if (oldColor != color) dfs(image, imageSize, imageColSize[0], sr, sc, oldColor, color);
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}