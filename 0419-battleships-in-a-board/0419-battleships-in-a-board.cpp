class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board.front().size(); c++) {
                if(board[r][c] == '.') {
                    continue;
                }
                bool above = r > 0 && board[r-1][c] == 'X';
                if(above) {
                    continue;
                }
                bool left = c > 0 && board[r][c-1] == 'X';
                if(left) {
                    continue;
                }
                res++;

            }
        }
        return res;
    }
};