int f(int n,int m,vector<vector<int>>grid)
{
    if(n==0 && m==0){
        return grid[0][0];
    }
    if(n<0 ||m<0){
        return 1e9;
    }
    int sum1=grid[n][m]+f(n-1,m,grid);
    int sum2=grid[n][m]+f(n,m-1,grid);
    return min(sum1,sum2);
}


int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
   return f(n-1,m-1,grid);
}