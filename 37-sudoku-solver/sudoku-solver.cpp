class Solution {
public:
int row[9][10] = {false};
int col[9][10] = {false};
int box[9][10] = {false};
bool solved = false;

void solve(vector<vector<char>>& board, int i, int j) {
    if(i == 9) {
        solved = true;
        return;
    }

    int next_row = (j==8) ? i+1 : i;
    int next_col = (j==8) ? 0 : j+1;

    if(board[i][j] != '.') solve(board, next_row, next_col);
    else {
        int boxId = (i/3)*3 + (j/3);
        for(int k = 1; k <= 9; k++) {
            if(!row[i][k] && !col[j][k] && !box[boxId][k]) {board[i][j] = '0' + k;
            row[i][k] = col[j][k] = box[boxId][k] = true;
            solve(board, next_row, next_col);
            if(solved == true) return;
            board[i][j] = '.';
            row[i][k] = col[j][k] = box[boxId][k] = false;}
        }
    }
}

    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0 ;i < 9; i++) {
            for(int j = 0 ; j < 9; j++) {
                if(board[i][j] != '.') {
                    int boxId = (i/3)*3 + (j/3);
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = box[boxId][num] = true;
                }
            }
        }
        solve(board, 0, 0);
    }
};