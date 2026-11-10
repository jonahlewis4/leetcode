class Trie{
    array<Trie*, 26> children;
    int val = 0;
    int singleVal = 0;
public:
    void insert(const string& key, int val) {
        Trie* t = this;
        for(int i = 0; i < key.size(); i++) {
            int c = key[i];
            Trie* child = t->children[c - 'a'];
            if(!child) {
                child = new Trie();
            }
            t->children[c-'a'] = child;
            child->val += val;
            t = child;
        }
        if(t->singleVal) {
            int equalizer = -t->singleVal;
            t->singleVal = 0;
            insert(key, equalizer);
        }
        t->singleVal = val;
    }

    int sum(const string& prefix) {
        Trie* t = this;
        for(int i = 0; i < prefix.size(); i++) {
            int c = prefix[i];
            Trie* child = t->children[c - 'a'];
            if(!child) {
                return 0;
            }
            t = child;
        }
        return t->val;
    }
};
class MapSum : public Trie {};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */