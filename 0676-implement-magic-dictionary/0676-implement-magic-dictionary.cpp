class MagicDictionary {
    struct Trie{
        bool end = false;
        array<Trie*, 26> children{};
        Trie(){}
        Trie(vector<string>& dict){
            for(const string& s : dict) {
                insert(s, 0);
            }
        }

        void insert(const string& s, int i) {
            if(i >= s.size()) {
                end = true;
                return;
            }

            char c = s[i];
            int cI = c - 'a';
            if(!children[cI]){
                children[cI] = new Trie();
            }
            children[cI]->insert(s, i + 1);
        }

        bool hasWithWildCard(const string& s, int i, bool wildCardUsed) const {
            if(i == s.size()) {
                return end && wildCardUsed;
            }

            char c = s[i];
            int cI = c - 'a';
            
            if(!wildCardUsed){
                for(int idx = 0; idx < children.size(); idx++) {
                    if(cI == idx) {
                        continue;
                    }
                    Trie const *const child = children[idx];
                    if(child && child->hasWithWildCard(s, i+1, true)){
                        return true;
                    }
                }
            }
            if(children[cI]){
                return children[cI]->hasWithWildCard(s, i+1, wildCardUsed);
            }
            
            return false;
        }
    };
public:
    Trie t;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        t = Trie(dictionary);
    }
    
    bool search(string searchWord) {
        return t.hasWithWildCard(searchWord, 0, false);

    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */