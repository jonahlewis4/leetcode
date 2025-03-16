class Solution {
    class Trie{
        bool isEnd = false;
        array<unique_ptr<Trie>, 26> children;
        
        public:
        void insert(const string& word){
            Trie* cur = this;
            for(int i = 0; i < word.size(); i++){
                int idx = word[i] - 'a';
                if(cur->children[idx] == nullptr){
                    cur->children[idx] = make_unique<Trie>();
                }
                cur = cur->children[idx].get();
            }
            cur->isEnd = true;
        }
        bool find(const string& word){
            Trie* cur = this;
            for(int i = 0; i < word.size(); i++){
                int idx = word[i] - 'a';
                if(cur->children[idx] == nullptr){
                    return false;
                }
                cur = cur->children[idx].get();
            }
            return cur->isEnd;
        }
        Trie* get(const char c) const {
            return children[c - 'a'].get();
        }
        bool isWord() const {
            return isEnd;
        }
    };

    Trie trie;
    vector<vector<char>>* board;
    vector<string> res;
    string curWord = "";
    vector<vector<bool>> visited;
    unordered_set<string> inRes;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(const string& word : words){
            trie.insert(word);
        }
        this->board = &board;
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                calc(&trie, row, col);
            }
        }
        return res;
    }
    void calc(Trie* cur, int row, int col){
        if(cur == nullptr){
            return;
        }
        if(row < 0 || row >= board->size() || col < 0 || col >= (*board)[row].size()){
            return;
        }
        if(visited[row][col]){
            return;
        }
        char c = (*board)[row][col];
        Trie* next = cur->get(c);
        if(!next){
            return;
        } else {
            curWord.push_back(c);
            visited[row][col] = true;
            if(next->isWord()){
                if(inRes.find(curWord) == inRes.end()){
                    res.push_back(curWord);
                    inRes.insert(curWord);

                }
                
            }
            calc(next, row + 1, col);
            calc(next, row - 1, col);
            calc(next, row, col + 1);
            calc(next, row, col - 1);
            curWord.pop_back();
            visited[row][col] = false;
        }

    }
};