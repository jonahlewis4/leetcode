class Solution {
    static vector<pair<int, int>> dirs;
    static int surrounding(vector<vector<char>>& board, int r, int c) {
        int total = 0;
        for(const pair<int, int>& dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;
            if(newR < 0 || newC < 0 || newR >= board.size() || newC >= board.front().size()) {
                continue;
            }

            char cell = board[newR][newC];
            if(cell == 'M' || cell == 'X'){
                total++;
            }
        }
        return total;
    }
    static bool blankSweep(vector<vector<char>>& board, int r, int c) {
        if(board[r][c] != 'E') {
            return false;
        }
        int surround = surrounding(board,r,c);
        if(surround == 0) {
            board[r][c] = 'B';
            for(const pair<int, int>& dir : dirs) {
                int newR = r + dir.first;
                int newC = c + dir.second;
                if(newR < 0 || newC < 0 || newR >= board.size() || newC >= board.front().size()) {
                    continue;
                }
                blankSweep(board, newR, newC);
            }
            return true;
        } else {
            board[r][c] = surround + '0';
        }
        return false;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click.front();
        int c = click.back();

        char& square = board[r][c];
        switch (square) {
            case 'M': {
                square = 'X';
                return board;
            }
            case 'E': {
                blankSweep(board, r, c);
                return board;
            }
            default:
        }

        return {};
    }
};
vector<pair<int, int>> Solution::dirs = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0,1},
        {1,-1},
        {1,0},
        {1,1}
    };