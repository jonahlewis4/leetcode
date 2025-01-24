class RandomizedSet {
    private: 
    unordered_map<int, int> map;
    vector<int> randomizer;


public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) == map.end()){
            map[val] = randomizer.size();
            randomizer.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(map.find(val) != map.end()){
            if(map[val] == randomizer.size() - 1){
                randomizer.pop_back();
            } else {
                int endI = randomizer.size() - 1;
                int removeI = map[val];
                map[randomizer[endI]] = removeI;
                swap(randomizer[endI], randomizer[removeI]);
                randomizer.pop_back();
            }
            map.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return randomizer[rand() % randomizer.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */