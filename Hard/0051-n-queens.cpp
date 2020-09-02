class Solution {
public:
    int visitCol, visitDiagonal, visitBackDiagonal;
    int n;
    vector<vector<string>> res;
    vector<string> chessboard;

    void dfs(int x) {
        if (x == n) {
            res.push_back(chessboard);
            return;
        }
        for (int y = 0; y < n; y++) {
            if (getBit(visitCol, y) && getBit(visitDiagonal, x + y) && getBit(visitBackDiagonal, x - y + n)) {
                filpBit(visitCol, y), filpBit(visitDiagonal, x + y), filpBit(visitBackDiagonal, x - y + n);
                chessboard[x][y] = 'Q';
                dfs(x + 1);
                chessboard[x][y] = '.';
                filpBit(visitCol, y), filpBit(visitDiagonal, x + y), filpBit(visitBackDiagonal, x - y + n);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        visitCol = visitDiagonal = visitBackDiagonal = (1 << (2 * n)) - 1;
        this->n = n;
        res.clear();
        chessboard = vector<string>(n, string(n, '.'));
        dfs(0);
        return res;
    }

    static int getBit(int value, int bitIndex) {
        return (value >> bitIndex) & 1;
    }

    static void filpBit(int& value, int bitIndex) {
        value ^= 1 << bitIndex;
    }
};
