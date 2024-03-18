class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> visited(n,vector<int> (m,-1));
	    
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0) {
	                q.push({i,j});
	                visited[i][j]=0;
	            }
	        }
	    }
	    int count=1;
	    int x[]={1,-1,0,0};
	    int y[]={0,0,1,-1};
	    while(!q.empty()){
	        int len=q.size();
	        for(int i=0;i<len;i++){
	            int row=q.front().first;
	            int col=q.front().second;
	            q.pop();
	            for(int k=0;k<4;k++){
	                int ti=row+x[k];
	                int tj=col+y[k];
	                
	                if(ti>=0&&ti<n&&tj>=0&&tj<m&&visited[ti][tj]==-1){
	                    visited[ti][tj]=count;
	                    q.push({ti,tj});
	                }
	            }
	        }
	        count++;
	        
	    }
	    return visited;
	}
};