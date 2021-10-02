/*********************************/
/*
就是 轻视了if语句的规律
*/
#include <stdio.h>
#define size 50
int CountArea(int grid[][size], int i, int j, int row, int col)
{
    int count= 1;        //初始化为当前地块的面积，相当于遍历了当前地块。
    grid[i][j]=
        0;        //为了避免重复计算同一块岛，将遍历过的土地（1）设置为海洋（0）。
                  /* Your code should be written here.*/
                  /*    grid[i][j]=2;count=0;
                  for(int r=0;r<20;r++){//随便输的20
                      for (int i = 0; i < row; i++){
                      for (int j = 0; j < col; j++){
                          if (grid[i][j]==2){
                              if(grid[i][j+1]==1){
                                  grid[i][j+1]=2;
                              }else if(grid[i][j-1]==1){
                                  grid[i][j-1]=2;
                              }else if(grid[i+1][j]==1){
                                  grid[i+1][j]=2;
                              }else if(grid[i-1][j]==1){
                                  grid[i-1][j]=2;
                              }else
                  if(grid[i][j+1]==2||grid[i][j-1]==2||grid[i+1][j]==2||grid[i-1][j]==2){
                                  continue;
                              }else{
                                  grid[i][j]=0;
                                  count=1;
                                  return count;
                              }
                          }
                      }
                  }
                  }
                  for (int i = 0; i < row; i++){
                      for (int j = 0; j < col; j++){
                          if (grid[i][j]==2){
                              count++;
                              grid[i][j]=0;
                          }
                      }
                  }
                   */
                  /*最强递归*/
    if (grid[i][j + 1] == 1) {
        count= count + CountArea(grid, i, j + 1, row, col);
    }
    if (grid[i][j - 1] == 1) {
        count= count + CountArea(grid, i, j - 1, row, col);
    }
    if (grid[i + 1][j] == 1) {
        count= count + CountArea(grid, i + 1, j, row, col);
    }
    if (grid[i - 1][j] == 1) {
        count= count + CountArea(grid, i - 1, j, row, col);
    }
    return count;
}
int maxAreaOfIsland(int grid[][size], int row, int col)
{
    int maxArea= 0;
    int count= 0;
    for (int i= 0; i < row; i++) {
        for (int j= 0; j < col; j++) {
            if (grid[i][j] == 1) {        //表示发现岛屿
                count= CountArea(grid, i, j, row, col);
                maxArea= maxArea > count ? maxArea : count;
            }
        }
    }
    return maxArea;
}
int main()
{
    int row, col;
    int grid[size][size];
    scanf("%d%d", &row, &col);        //输入二维数组的行和列
    for (int i= 0; i < row; i++) {
        for (int j= 0; j < col; j++) {
            scanf("%d", &grid[i][j]);        //输入二维数组的元素
        }
    }
    int area;
    area= maxAreaOfIsland(grid, row, col);
    printf("%d\n", area);        //输出最大的岛屿面积
    return 0;
}
