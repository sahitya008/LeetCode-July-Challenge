class Solution {
   public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
             int rows= grid.size();
             int col= grid[0].size();
             int result=0;
             for(int i=0;i<rows;i++){
                for(int j=0;j<col;j++){
                      if(grid[i][j])
                        result= max(result,dfs(grid,i,j));
                }
            }
            return result;
        }
    private:
    //int rows,col;
    int dfs(vector<vector<int>>& grid, int i, int j ){
        int rows= grid.size();
         int col= grid[0].size();
        if(i<0 || j<0 || i>=rows || j>=col || !grid[i][j])
            return 0;
            grid[i][j]=0;   //marking node as visited
            return 1+(dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1));
        }
};