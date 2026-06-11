class Solution {
    constexpr static array<pair<int, int>, 8> dirs = {{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},   {1, 1},
    }};
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> copy = board;
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board.front().size(); c++) {
                int alive = 0;
                for(const auto [dr, dc] : dirs) {
                    int newR = r + dr;
                    int newC = c + dc;
                    if(newR < 0 || newC < 0 || newR >= board.size() || newC >= board.front().size()) {
                        continue;
                    }

                    if(copy[newR][newC]) {
                        alive++;
                    }
                }

                if(copy[r][c] && alive < 2) {
                    board[r][c] = false;
                } else if (copy[r][c] && (alive == 2 || alive == 3)){
                    board[r][c] = true;
                } else if (copy[r][c] && alive > 3) {
                    board[r][c] = false;
                } else if (!copy[r][c] && alive == 3) {
                    board[r][c] = true;
                }
            }
        }
    }
};