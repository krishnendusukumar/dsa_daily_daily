class Solution {
public:
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    void dfs(const vector<vector<int>>& grid, int r, int c, int t,
             vector<vector<int>>& dist) {
        int m = grid.size(), n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n) return; // OOB
        if (grid[r][c] == 0) return;                    // empty blocks spread
        if (t >= dist[r][c]) return;                    // already have better/equal

        dist[r][c] = t;                                 // best time so far

        for (int k = 0; k < 4; ++k) {
            dfs(grid, r + dr[k], c + dc[k], t + 1, dist);
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // start DFS from all initially rotten oranges with time 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) dfs(grid, i, j, 0, dist);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {              // only fresh need to be reached
                    if (dist[i][j] == INT_MAX) return -1; // unreachable fresh
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        return ans; // 0 if no fresh oranges exist
    }
};
