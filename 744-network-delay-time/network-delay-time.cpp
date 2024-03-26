class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto i: times){
            adj[i[0]].push_back({i[1],i[2]});
        }

        set<pair<int,int>> st;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        st.insert({0,k});
        while(!st.empty()){
            auto tp=*(st.begin());
            int node=tp.second;
            int distance=tp.first;
            st.erase(st.begin());
            for(auto adjPair: adj[node]){
                int adjnode=adjPair.first;
                int adjdist=adjPair.second;

                if(distance+adjdist<dist[adjnode]){
                    if(dist[adjnode]!=INT_MAX){
                        st.erase({dist[adjnode],adjnode});
                    }

                    dist[adjnode]=distance+adjdist;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }

        int maxi=dist[1];
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX) return -1;
            maxi=max(dist[i],maxi);
        }
        return maxi;
    }
};