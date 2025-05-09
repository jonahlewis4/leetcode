class TwoSum {
private:
    unordered_map<int, int> set;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        set[number]++;
    }
    
    bool find(int value) {
        for(auto const &num : set){
            long number = num.first;
            long comp = value - number;
            if(comp == number){
                if(set[number] >= 2){
                    return true;
                }
            } else {
                if(set.find(comp) != set.end()){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */