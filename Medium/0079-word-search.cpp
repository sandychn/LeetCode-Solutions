class Solution {
public:
    int n, m;
    vector<vector<char>> board;
    string word;

    bool dfs(int x, int y, int pos) {
        if (pos == word.size()) return true;

        int tmp = board[x][y];
        board[x][y] = '$';

        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};

        bool res = false;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (0 <= newX && newX < n && 0 <= newY && newY < m && board[newX][newY] == word[pos]) {
                if (dfs(newX, newY, pos + 1)) {
                    res = true;
                    break;
                }
            }
        }

        board[x][y] = tmp;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        this->board = board;
        this->word = word;

        char first = word[0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == first) {
                    if (dfs(i, j, 1)) return true;
                }
            }
        }

        return false;
    }
};
