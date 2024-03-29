class DisjointSet {
    public:
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
                int n=grid.size();
        DisjointSet ds(n*n);
        int rownum[]={-1,0,1,0};
        int colnum[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int row=i;
                int col=j;
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nrow=row+rownum[k];
                        int ncol=col+colnum[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                            int v=n*nrow+ncol;
                            int u=n*row+col;
                            if(ds.findUPar(v)!=ds.findUPar(u)){
                                ds.unionBySize(u,v);
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int row=i;
                    int col=j;
                    int count=1;
                    set<int>st;
                    for(int k=0;k<4;k++){
                        int nrow=row+rownum[k];
                        int ncol=col+colnum[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                            int u=n*nrow+ncol;
                            int par=ds.findUPar(u);
                            if(st.find(par)==st.end()){
                                count+=ds.size[par];
                                st.insert(par);
                            }
                            
                        }
                    }
                    ans=max(ans,count);
                }
            }
        }
        if(ans==0){
            return n*n;
        }
        return ans;
    }
};