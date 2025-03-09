class Solution {
private: 
    vector<vector<char>> board;
    string word;
    bool exists;
    vector<vector<bool>> visited;
public:
    bool exist(const vector<vector<char>>& board, const string word) {
        this->board = board;
        this->word = word;
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        exists = false;
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                calc(0, row, col);
            }
        }
        return exists;
    }
    void calc(int i, int row, int col){
        if(exists){
            return;
        }
        if(i == word.size()){
            cout<<i<<endl;
            exists = true;
            return;
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[row].size()){
            return;
        }
        
        if(word[i] != board[row][col]){
            return;
        }
        if(visited[row][col]){
            return;
        }
        visited[row][col] = true;
        calc(i + 1, row - 1, col);
        calc(i + 1, row, col - 1);
        calc(i + 1, row + 1, col);
        calc(i + 1, row, col + 1);
        visited[row][col] = false;

    }
};