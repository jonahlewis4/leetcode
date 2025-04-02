class Solution {
public:
    void solve(vector<vector<char>>& board) const {
        //dfs all on the border. Any connected to it we will set to B for border

        //loop through and set all O's to X and all B's to O

        traceBorder(board);
        resolve(board);
    }

    void traceBorder(vector<vector<char>>& board) const{
        for(int r = 0; r < board.size(); r++){
            if(board[r][0] == 'O'){
                trace(board, r, 0);
            }
            if(board[r][board[r].size() - 1] == 'O'){
                trace(board, r, board[r].size() - 1);
            }
        }

        for(int c = 1; c < board[0].size() - 1; c++){
            if(board[0][c] == 'O'){
                trace(board, 0, c);
            }
            if(board[board.size() - 1][c] == 'O'){
                trace(board, board.size() - 1, c);
            }
        }
    }

    void trace(vector<vector<char>> & board, int r, int c) const{
        if(r < 0 || c < 0 || r >= board.size() || c >= board[r].size()){
            return;
        }
        if(board[r][c] == 'B' || board[r][c] == 'X'){
            return;
        }
        board[r][c] = 'B';
        
        trace(board, r + 1, c);
        trace(board, r - 1, c);
        trace(board, r, c - 1);
        trace(board, r, c + 1);
    }

    void resolve(vector<vector<char>>& board) const{
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                if(board[r][c] == 'B'){
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }
    }
};