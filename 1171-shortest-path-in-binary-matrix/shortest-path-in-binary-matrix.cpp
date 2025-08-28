class Solution {
public:
const vector<int> dr = {-1,-1,-1,0,0,1,1,1};
const vector<int> dc = {-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int,int>>> q;
        q.push({1, {0, 0}});
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        memo[0][0] = 1;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // blocked

        while(!q.empty()) {
            auto pair = q.front(); q.pop();
            auto [i, j] = pair.second;
            int dis = pair.first;

            if(i == n-1 && j == n-1) {
                return dis;
            }

            for(int k = 0; k < 8; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    if(memo[nr][nc] > 1+dis) {
                    memo[nr][nc] = 1+dis;
                    q.push({1+dis, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};