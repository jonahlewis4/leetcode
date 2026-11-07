class MagicDictionary {
    struct Trie {
        bool end = false;
        array<Trie*, 26> children{};

        Trie() {}
        
        Trie(const vector<string>& dict) {
            for (const string& s : dict) {
                insert(s);
            }
        }

        void insert(const string& s) {
            Trie* t = this;
            for(int i = 0; i < s.size(); i++) {
                char c = s[i];
                int cI = c - 'a';
                if (!t->children[cI]) {
                    t->children[cI] = new Trie();
                }
                t = t->children[cI];
            }
            t->end = true;
        }

        bool exactMatch(const string& s, int startI) const {
            const Trie* curr = this;
            for (int i = startI; i < s.size(); ++i) {
                int cI = s[i] - 'a';
                if (!curr->children[cI]) {
                    return false;
                }
                curr = curr->children[cI];
            }
            return curr->end;
        }

        bool searchWithWildCard(const string& s) const {
            const Trie* curr = this;
            int n = s.size();

            for (int i = 0; i < n; ++i) {
                if (!curr) break;

                char c = s[i];
                int cI = c - 'a';

                for (int idx = 0; idx < 26; ++idx) {
                    if (idx == cI) continue;
                    if (curr->children[idx]) {
                        if (curr->children[idx]->exactMatch(s, i + 1)) {
                            return true;
                        }
                    }
                }

                curr = curr->children[cI];
            }

            return false;
        }
    };

public:
    Trie t;
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        t = Trie(dictionary);
    }
    
    bool search(string searchWord) {
        return t.searchWithWildCard(searchWord);
    }
};