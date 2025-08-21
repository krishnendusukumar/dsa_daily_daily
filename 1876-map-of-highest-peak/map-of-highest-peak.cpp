class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }


        int dr[] = {-1, +1, 0, 0};
        int dc[] = {0 , 0,-1, +1};
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

                if(new_row >= 0 && new_col >= 0 && new_row < n && new_col < m && visited[new_row][new_col] == 0){
                    q.push({{new_row, new_col}, steps+1});
                    visited[new_row][new_col] = 1;
                }
            }
        }
        return dist;
    }   
};



// while(!q.empty()) {

//             if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && visited[new_row][new_col] == 0){
//                 q.push({{new_row, new_col}, steps + 1});
//                 visited[new_row][new_col] = 1;
//             }
//         }
//     }
//         return dist;
//     }
// };