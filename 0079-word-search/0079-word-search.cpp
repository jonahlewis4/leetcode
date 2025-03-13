class Solution {
private: 
    vector<vector<char>> board;
    string word;
    bool res;
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->res = false; 
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                calc(0, row, col);
            }
        }
        return res;
    }
    void calc(const int i, const int row, const int col) {
        if(i == word.size()){
            res = true;
            return;
        }
        
        if(row < 0 or row >= board.size() or col < 0 or col >= board[row].size()){
            return;
        }
        if(visited[row][col]){
            return;
        }
        if(word[i] != board[row][col]){
            return;
        }
        visited[row][col] = true;
        calc(i + 1, row + 1, col);
        calc(i + 1, row - 1, col);
        calc(i + 1, row, col + 1);
        calc(i + 1, row, col - 1);
        visited[row][col] = false;
        


    }
};