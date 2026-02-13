/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  *returnSize = matrixSize * (*matrixColSize);
  int* arr = (int*)malloc((*returnSize) * sizeof(int));
   int k=0,top=0,left=0,right=*matrixColSize-1,bottom=matrixSize-1;
   while(top<=bottom && left<=right)
   {for(int i=left;i<=right;i++)
      arr[k++]=matrix[top][i];
      top++;
    for(int i=top;i<=bottom;i++)
     arr[k++]=matrix[i][right];
     right--;
    if(top<=bottom)
    {
        for(int i=right;i>=left;i--)
        arr[k++]=matrix[bottom][i];
          bottom--;          
    } 
    if(left<=right)
    {
        for(int i=bottom;i>=top;i--)
        arr[k++]=matrix[i][left];
       left++;
    }
   }
   return arr;
}