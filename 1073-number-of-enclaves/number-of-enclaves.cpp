class Solution {
public:
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    int maxi = INT_MIN;


void dfs(int r,int c, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<vector<int>>& inStack){
    int n = grid.size(), m = grid[0].size();
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if(grid[r][c] == 0 || visited[r][c]) return;

    visited[r][c] = 1;
    for(int i = 0; i < 4; i++) {
        dfs(r+dr[i], c+dc[i], grid, visited, inStack);
    }
    return;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> inStack(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) { 
            dfs(i, 0, grid, visited, inStack);
            dfs(i, m-1, grid, visited, inStack);
        }
        for(int j = 0; j < m; j++) { 
            dfs(0, j, grid, visited, inStack);
            dfs(n-1, j, grid, visited, inStack);
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ; j++) {
                if(visited[i][j] == 0 && grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};