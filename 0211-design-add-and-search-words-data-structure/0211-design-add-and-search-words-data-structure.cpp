class WordDictionary {
    struct Trie{
        bool isEnd = false;
        array<unique_ptr<Trie>, 26> children;
    };
    unique_ptr<Trie> root = make_unique<Trie>();
public:
    WordDictionary() {
        
    }
    
    void addWord(const string& word) {
        auto cur = root.get();
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = make_unique<Trie>();
            }
            cur = cur->children[idx].get();
        }
        cur->isEnd = true;
    }
    
    bool search(const string& word) {
        return searchPastIndex(word, 0, root.get());
    }

    bool searchPastIndex(const string& word, int i, Trie* cur){
        if(cur == nullptr){
            return false;
        }
        if(i == word.size() && cur->isEnd){
            return true;
        }
        if(i >= word.size()){
            return false;
        }

        if(word[i] == '.'){
            for(const auto & trie : cur->children){
                if(searchPastIndex(word, i + 1, trie.get())){
                    return true;
                }
            }
        } else {
            return searchPastIndex(word, i + 1, cur->children[word[i] - 'a'].get());
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */