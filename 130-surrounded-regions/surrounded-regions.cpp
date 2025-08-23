class Solution {
public:

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

  void dfs(int r, int c, vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m) return;
        if (b[r][c] != 'O') return;
        b[r][c] = '#';                 // mark border-connected O as safe
        for (int k = 0; k < 4; ++k)
            dfs(r + dr[k], c + dc[k], b);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                if((board[i][j] == 'O') && (i == 0 || j == 0 || i == n-1 || j == m-1)) 
                {
                    board[i][j] = '#';
                    if(i+1 < n) dfs(i+1, j, board);
                    if(j+1 < m) dfs(i, j+1, board);
                    if(i - 1 >= 0) dfs(i-1, j, board);
                    if(j - 1 >= 0) dfs(i, j-1, board);
                }
            }
        }

         for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                board[i][j] = (board[i][j] == 'O' ? 'X' : (board[i][j] == '#'? 'O' : board[i][j]));
    }
};