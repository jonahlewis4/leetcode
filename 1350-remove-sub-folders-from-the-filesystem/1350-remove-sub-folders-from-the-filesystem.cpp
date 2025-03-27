class Solution {
private:
    class Trie {
        bool isEnd = false;
        array<unique_ptr<Trie>, 27> children;

        int hash(char c) const {
            if(c == '/'){
                return 26;
            }
            return c - 'a';
        }

    public:
        void insert(const string & s){
            Trie* cur = this;
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                int idx = hash(c);
                if(c == '/' && cur -> isEnd){
                    return;
                }
                if(cur->children[idx] == nullptr){
                    cur->children[idx] = make_unique<Trie>();
                }
                cur = cur->children[idx].get();
            }
            cur->isEnd = true;
            
        }
        bool isSub(const string & s){
            Trie* cur = this;
            for(int i = 0; i < s.size(); i++){
                // if(cur == nullptr){
                //     return true;
                // }
                char c = s[i];
                if(c == '/' && cur->isEnd){
                    return true;
                }
                int idx = hash(c);
                cur = cur->children[idx].get();
            }
            return false;
        }

    };

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for(auto & str : folder){
            trie.insert(str);
        }
        vector<string> res;
        for(const auto & str : folder){
            if(trie.isSub(str)){
                continue;
            }
            res.push_back(str);
        }
        return res;
    }
};