class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> topo;
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    while(!q.empty()){
	        int len=q.size();
	        for(int i=0;i<len;i++){
	            ans.push_back(q.front());
	            int node=q.front();
	            q.pop();
	            for(auto j: adj[node]){
	                indegree[j]--;
	                if(indegree[j]==0) q.push(j);
	            }
	        }
	         
	         
	    }
	    //for(auto i: ans) cout<<i<<" ";
	    if(ans.size()<V) return {};
	    return ans;
    }
};