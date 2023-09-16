class Solution {
public:
bool dfs(int i,int j,vector<vector<int>>&grid){
   if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
   return false; //out of boundary
   //check 4 directions
   if(grid[i][j]==1)return true;
   grid[i][j]=1;
   bool left_side=dfs(i,j-1,grid);
   bool right_side=dfs(i,j+1,grid);
   bool up_side=dfs(i-1,j,grid);
   bool down_side=dfs(i+1,j,grid);
   return left_side&&right_side&&up_side&&down_side;
}
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
       //vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==0){
                   if(dfs(i,j,grid))
                   count++;
               }
           }
       }
        return count;
    }
};