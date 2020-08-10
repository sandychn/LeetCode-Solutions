class Solution {
public:
    int row, col;

    void dfs(int x, int y, vector<vector<char>>& board) {
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};
        
        board[x][y] = '@';
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (0 <= newX && newX < row && 0 <= newY && newY < col && board[newX][newY] == 'O') {
                dfs(newX, newY, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        row = board.size();
        col = board[0].size();

        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][col - 1] == 'O') {
                dfs(i, col - 1, board);
            }
        }
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i, board);
            }
            if (board[row - 1][i] == 'O') {
                dfs(row - 1, i, board);
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '@') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
