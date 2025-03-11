class SparseVector {
private:
    int length;
    unordered_map<int, int> valAtIndex;
public:
    
    SparseVector(vector<int> &nums) {
        length = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                continue;
            }
            valAtIndex[i] = nums[i];
        }    
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        if(valAtIndex.size() < vec.size()){
            for(const auto &[index, value] : valAtIndex){
                if(vec[index] != 0){
                    sum += vec[index] * value;
                }
            }
        } else {
            for(const auto &[index, value] : vec.valAtIndex){
                if((*this)[index] != 0){
                    sum += (*this)[index] * value;
                }
            }
        }
        

        return sum;
    }
    int operator[](const int i){
        if(valAtIndex.find(i) == valAtIndex.end()){
            return 0;
        }
        return valAtIndex[i];
    }
    int size() const {
        cout<<"size: "<<valAtIndex.size()<<endl;
        return valAtIndex.size();
    }

};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);