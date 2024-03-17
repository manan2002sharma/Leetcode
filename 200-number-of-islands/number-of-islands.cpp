class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j){
        vis[i][j]=1;
        int it[]={+1,-1,0,0};
        int jt[]={0,0,+1,-1};
        
        for(int k=0;k<4;k++){
            int ti=i+it[k];
            int tj=j+jt[k];
            if(ti>=0&&ti<grid.size()&&tj>=0&&tj<grid[0].size()&&vis[ti][tj]==0&&grid[ti][tj]=='1'){
                dfs(grid,vis,ti,tj);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&visited[i][j]==0){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};