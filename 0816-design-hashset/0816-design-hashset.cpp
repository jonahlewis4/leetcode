class MyHashSet {
    vector<set<int>> oset = vector<set<int>>(10000);

    int hash(int key) const {
        return key % 10000;
    } 


public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        oset[hash(key)].insert(key);
    }
    
    void remove(int key) {
        oset[hash(key)].erase(key);
    }
    
    bool contains(int key) {
        return oset[hash(key)].count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */