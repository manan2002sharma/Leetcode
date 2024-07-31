class Solution {
public:
    void dfs(int node,vector<vector<int>> adj,int parent,double currNodeProb,double &ans,int target,int t){
        
        double child=adj[node].size();
        if(parent!=-1) child--;
        cout<<node<<" "<<t<<" "<<currNodeProb<<" "<<child<<endl;
        if(node==target){
            if(t==0){
                ans=currNodeProb;
            }else if(t>0){
                if(child==0) ans=currNodeProb;
            }
            return;
        }

        for(auto i: adj[node]){
            if(i!=parent){
                dfs(i,adj,node,currNodeProb/child,ans,target,t-1);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);        
            adj[i[1]].push_back(i[0]);
        }
        double ans=0;
        dfs(1,adj,-1,1,ans,target,t);
        return ans;
    }
};