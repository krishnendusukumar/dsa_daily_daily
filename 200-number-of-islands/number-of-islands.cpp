class Solution {
public:
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c, vector<vector<int>>& inStack) {
    int n = grid.size();
    int m = grid[0].size();

    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if(grid[r][c] == '0') return;
    if(inStack[r][c] == 1 || visited[r][c]) return;

    visited[r][c] = 1;
    inStack[r][c] = 1;
    for(int i = 0; i < 4; i++) {
        dfs(grid, visited, r+dr[i], c+dc[i], inStack);
    }
    inStack[r][c] = 0;
}

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<vector<int>>inStack(n, vector<int>(m, 0));
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(grid, visited, i, j, inStack);
                }
            }
        }
        return count;
    }
};