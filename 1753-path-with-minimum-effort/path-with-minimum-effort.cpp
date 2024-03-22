class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int i = it.first;
            int j = it.second;

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int newDist = max(dist[i][j], abs(heights[i][j] - heights[ni][nj]));
                    if (newDist < dist[ni][nj]) {
                        dist[ni][nj] = newDist;
                        pq.push({ni, nj});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};