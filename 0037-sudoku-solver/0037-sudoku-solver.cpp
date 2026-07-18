class Solution {
    array<array<bool, 9>, 9> rows{};
    array<array<bool, 9>, 9> cols{};
    array<array<bool, 9>, 9> squares{};

    int solved = 0;


    bool validate(int r, int c, int i) const{
        if(rows[r][i - 1]) {
            return false;
        }
        if(cols[c][i - 1]) {
            return false;
        }

        int square = r/3*3 + c/3;
        if(squares[square][i - 1]) {
            return false;
        }
        return true;
    }    

    bool sweep(vector<vector<char>>& board, int startR, int startC) {
        if(solved == 81){
            return true;
        }
        for(int r = startR; r < board.size(); r++) {
            for(int c = startC; c < board.front().size(); c++) {
                if(board[r][c] != '.'){
                    continue;
                }

                for(int i = 1; i <= 9; i++) {
                    if(validate(r, c, i)){
                        board[r][c] = i + '0';
                        rows[r][i - 1] = true;
                        cols[c][i - 1] = true;
                        squares[r/3*3+c/3][i - 1] = true;
                        solved++;
                        bool result = sweep(board, r, c);
                        if(result) {
                            return true;
                        }
                        rows[r][i - 1] = false;
                        cols[c][i - 1] = false;
                        squares[r/3*3+c/3][i - 1] = false;
                        board[r][c] = '.';
                        solved--;
                    }
                }

                return false;
            }
            startC = 0;
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board.front().size(); c++) {
                char i = board[r][c];
                if(i == '.'){
                    continue;
                }
                i-='0';
                rows[r][i - 1] = true;
                cols[c][i - 1] = true;
                //cout<<r<<" "<<c<<endl;
                int square = r/3*3+c/3;
                //cout<<square<<endl;
                squares[square][i - 1] = true;
                solved++;
            }
        }
        while(!sweep(board, 0, 0)){}

    }
};