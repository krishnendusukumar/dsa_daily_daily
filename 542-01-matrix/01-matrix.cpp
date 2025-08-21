class Solution {
public:

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
void bfs(vector<vector<int>>& mat, vector<vector<int>>& visited, vector<vector<int>>& dist, int i, int j, int steps) {
        int n = mat.size(), m = mat[0].size();
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
    queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> dist(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ;j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

    while(!q.empty()) {
        auto it = q.front();q.pop();
        auto itr = it.first;
        int steps = it.second;
        int row = itr.first;
        int col = itr.second;

        dist[row][col] = steps;
        for(int k = 0; k < 4; k++) {
            int new_row = row + dr[k];
            int new_col = col + dc[k];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && visited[new_row][new_col] == 0){
                q.push({{new_row, new_col}, steps + 1});
                visited[new_row][new_col] = 1;
            }
        }
    }
        return dist;
    }
};