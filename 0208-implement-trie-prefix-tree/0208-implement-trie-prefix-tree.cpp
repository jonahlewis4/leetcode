class Trie {
private:
    struct node {
        bool isEnd = false;
        array<unique_ptr<node>, 26> children;
    };
    unique_ptr<node> root;
public:
    Trie() {
        root = make_unique<node>();
    }
    
    void insert(string word) {
        node* cur = root.get();
        for(int i = 0; i < word.size(); i++){
            if(cur->children[word[i] - 'a'] == nullptr){
                cur->children[word[i] - 'a'] = make_unique<node>();
            }
            cur = cur->children[word[i] - 'a'].get();
        }
        cur->isEnd = true;
    }
    
    bool search(const string &word) {
        node* cur = root.get();
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(cur->children[idx] == nullptr){
                return false;
            }
            cur = cur->children[idx].get();
        }
        return cur->isEnd;
    }
    
    bool startsWith(const string &prefix) {
        node* cur = root.get();
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(cur->children[idx] == nullptr){
                return false;
            }
            cur = cur->children[idx].get();
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */