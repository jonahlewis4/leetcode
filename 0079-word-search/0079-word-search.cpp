class Solution {
private: 
vector<vector<bool>> visited;
bool exists;
string cur;
vector<vector<char>> board;
string word;
int idx;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->exists = false;
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size()));
        cur = "";
        this->board = board;
        this->word = word;
        idx = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                calc(i, j);
                if(exists){
                    return true;
                }
            }
        }
        
        return exists;
    }
    void calc(const int i, const int j){
        
        if(cur.size() > word.size() || exists == true || i >= board.size() || i < 0 || j >= board[i].size() || j < 0){
            return;
        }
        if(visited[i][j]){
            return;
        }
        cur += board[i][j];
        //cout<<"idx is: "<<idx<<endl;
        //cout<<"cur: "<<cur<<endl;
        if(cur[idx] != word[idx]){
            cur.pop_back();
            return;
        }
        //cout<<"they are the same "<<endl;
        idx++;
        if(cur == word){
            exists = true;
            cur.pop_back();
            idx--;
            return;
        }
        //cout<<cur<<endl;
        visited[i][j] = true;
        calc(i + 1, j);
        calc(i - 1, j);
        calc(i, j + 1);
        calc(i, j - 1);
        visited[i][j] = false;
        cur.pop_back();
        idx--;

    }
};