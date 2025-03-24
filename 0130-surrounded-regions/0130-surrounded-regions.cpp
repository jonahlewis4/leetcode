class Solution {
private:
public:
    void solve(vector<vector<char>>& board) {

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                if(r == 0 || r == board.size() - 1 || c == 0 || c == board[r].size() - 1){
                    calc(r, c, board);
                }                

            }
        }

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                if(board[r][c] == 'E'){
                    board[r][c] = 'O';
                } else {
                    board[r][c] = 'X';
                }
            }
        }
    }  

    void calc(int r, int c, vector<vector<char>>& board){
        if(r < 0 || c < 0 || r >= board.size() || c >= board[r].size()){
            return;
        }
        if(board[r][c] != 'O'){
            return;
        }
        board[r][c] = 'E';
        calc(r + 1, c, board);
        calc(r - 1, c, board);
        calc(r, c + 1, board);
        calc(r, c - 1, board);
    }

};