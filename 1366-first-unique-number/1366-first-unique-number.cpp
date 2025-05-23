class FirstUnique {
private:
    list<int> unique;
    unordered_map<int, list<int>::iterator> map;
    bool isUnique(int value) const {
        if(map.find(value) == map.end()){
            return true;
        }
        return false;
    }
    bool occursOnce(int value) const {
        if(map.find(value)->second != unique.end()){
            return true;
        }
        return false;
    }
public:
    FirstUnique(vector<int>& nums) {
        for(const auto & num : nums){
            add(num);
        }
    }
    
    int showFirstUnique() {
        if(unique.empty()){
            return -1;
        }
        return *unique.begin();
    }
    
    void add(int value) {
        if(isUnique(value)){
            unique.push_back(value);
            map[value] = prev(unique.end());
        } else if (occursOnce(value)) {
            list<int>::iterator it = map[value];
            unique.erase(it);
            map[value] = unique.end();
        }   
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */