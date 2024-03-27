class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        while(!q.empty())
        {
            int curr_room = q.front();
            q.pop();
            vis[curr_room] = true;
            for(auto i : rooms[curr_room])
            {
                if(vis[i] != true)
                    q.push(i);
            }
        }
        for(int i = 0 ; i < n; i++)
        {
            if(vis[i] == false)
                return false;
        }
        return true;
    }
    
};