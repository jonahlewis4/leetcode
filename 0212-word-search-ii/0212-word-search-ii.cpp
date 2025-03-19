class Solution {



private:
    class Trie {
        private:
            bool _isWord = false;
            array<unique_ptr<Trie>, 26> children;
            int _count = 0;
    
        public:
            void insert(const string& s){
                auto cur = this;
                for(int i = 0; i < s.size(); i++){
                    const char c = s[i];
                    if(cur->get(c) == nullptr){
                        cur->children[c - 'a'] = make_unique<Trie>();
                        _count++;
                    }
                    cur = cur->get(c);
                }
                cur->_isWord = true;
            }
            Trie* get(const char c) const {
                return children[c - 'a'].get();
            }
            bool isWord() const {
                return _isWord;
            }
            void unWord() {
                _isWord = false;
            }
    };
    vector<string> res;
    vector<vector<char>> board;
    Trie trie = Trie();
    string curWord = "";
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(const string & s : words){
            trie.insert(s);
        }

        this->board = board;
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

        if(cur->isWord()){
            cur->unWord();
            res.push_back(curWord);
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[row].size()){
            return;
        }
        
        if(board[row][col] < 'a'){
            return;
        }

        int c = board[row][col];
        curWord.push_back(c);
        board[row][col] -= 'a';
        Trie* next = cur->get(c);
        calc(next, row + 1, col);
        calc(next, row - 1, col);
        calc(next, row, col + 1);
        calc(next, row, col - 1);
        board[row][col] += 'a';
        curWord.pop_back();



    }
};