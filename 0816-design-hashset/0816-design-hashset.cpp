class MyHashSet {
    vector<list<int>> oset = vector<list<int>>(1000);

    int hash(int key) const {
        return key % 1000;
    } 


public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        oset[hash(key)].push_back(key);
    }
    
    void remove(int key) {
        auto itr = oset[hash(key)].begin();
        while(itr != oset[hash(key)].end()){
            if(*itr == key){
                oset[hash(key)].erase(itr);
                break;
            }
            itr = next(itr);
        }
    }
    
    bool contains(int key) {
        auto itr = oset[hash(key)].begin();
        while(itr != oset[hash(key)].end()){
            if(*itr == key){
                return true;
            }
            itr = next(itr);
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */