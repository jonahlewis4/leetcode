class Trie {
private:
    class Node {
    private:
        bool isEnd = false;
        array<unique_ptr<Node>, 26> children;
    public:
        bool isWord() const {
            return isEnd;
        }
        Node* get(char c){
            return children[c - 'a'].get();
        }
        void put(char c){
            children[c - 'a'] = make_unique<Node>();
        }
        void setEnd(){
            isEnd = true;
        }

    };

    Node root;
        
public:
    Trie() {
        
    }
    
    void insert(const string& word) {
        auto cur = &root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(cur->get(c) == nullptr){
                cur->put(c);
            }
            cur = cur->get(c);
        }
        cur->setEnd();
    }
    
    bool search(const string& word) {
        auto cur = &root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(cur->get(c) == nullptr){
                return false;
            }
            cur = cur->get(c);
        }
        return cur->isWord();
    }
    
    bool startsWith(const string& word) {
        auto cur = &root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(cur->get(c) == nullptr){
                return false;
            }
            cur = cur->get(c);
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