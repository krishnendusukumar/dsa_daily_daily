class Solution {
public:
bool check(int i, int j, vector<vector<char>>& arr) {
    if(arr[i][j] == '.') return true;

    char value = arr[i][j];

    for(int x = 0; x < 9; x++) {
    if(x != i && arr[x][j] == value) return false; // check column
    if(x != j && arr[i][x] == value) return false; // check row

    int startRow = (i/3) * 3;
        int startCol = (j/3) * 3;
        for(int r = startRow; r < startRow + 3; r++) {
            for(int c = startCol; c < startCol + 3; c++) {
                if((r != i || c != j) && arr[r][c] == value) return false;
            }
        }

}
    return true;
}
    bool isValidSudoku(vector<vector<char>>& arr) {
        for(int i = 0 ; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(!check(i, j, arr)) return false;
            }
        }
        return true;
    }
};