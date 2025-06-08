class MyHashMap {
    static constexpr unsigned int hashSize = 1000;
    vector<list<pair<int, int>>> lookup = vector<list<pair<int, int>>>(hashSize);
    int hash(int key) const {
        return key % hashSize;
    }
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto itr = lookup[hash(key)].begin();
        while(itr != lookup[hash(key)].end()){
            if (itr->first == key) {
                itr->second = value;
                return;
            }
            itr = next(itr);
        }
        lookup[hash(key)].push_back({key, value});
    }
    
    int get(int key) {
        auto itr = lookup[hash(key)].begin();
        while(itr != lookup[hash(key)].end()){
            if (itr->first == key) {
                return itr->second;
            }
            itr = next(itr);
        }
        return -1;
    }
    
    void remove(int key) {
        auto itr = lookup[hash(key)].begin();
        while(itr != lookup[hash(key)].end()){
            if (itr->first == key) {
                lookup[hash(key)].erase(itr);
                return;
            }
            itr = next(itr);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */