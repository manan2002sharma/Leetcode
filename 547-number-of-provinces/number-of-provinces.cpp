class Solution {
public:
    void dfs(int i,vector<int> &visited,vector<vector<int>> isConnected){
        visited[i]=1;
        for(int j=0;j<isConnected[i].size();j++){
            if(isConnected[i][j]==1&&i!=j&&visited[j]==-1) dfs(j,visited,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(i,visited,isConnected);
                ans++;
            }
            
        }
        return ans;
    }
};