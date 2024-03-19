class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                visited[i][0]=1;
                q.push({i,0});
            } 
            if(board[i][m-1]=='O') {
                visited[i][m-1]=1;
                q.push({i,m-1}); 
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O'){
                q.push({0,i}); 
                visited[0][i]=1;
            } 
            if(board[n-1][i]=='O') {
                visited[n-1][i]=1;
                q.push({n-1,i}); 
            }
        }

        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int col=q.front().first;
                int row=q.front().second;
                
                q.pop();
                for(int k=0;k<4;k++){
                    int ti=col+x[k];
                    int tj=row+y[k];
                    if(tj<m&&tj>=0&&ti<n&&ti>=0&&board[ti][tj]=='O'&&visited[ti][tj]==0){
                        visited[ti][tj]=1;
                        q.push({ti,tj});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};