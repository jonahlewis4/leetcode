class MyHashSet {
    vector<bool> oset = vector<bool>(1e6 + 1, false);
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        oset[key] = true;
    }
    
    void remove(int key) {
        oset[key] = false;
    }
    
    bool contains(int key) {
        return oset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */