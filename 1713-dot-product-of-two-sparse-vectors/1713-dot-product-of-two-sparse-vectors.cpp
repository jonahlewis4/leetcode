class SparseVector {
private:
    int length;
    unordered_map<int, int> valAtIndex;
public:
    
    SparseVector(vector<int> &nums) {
        length = nums.size();
        for(int i = 0; i < nums.size(); i++){
            valAtIndex[i] = nums[i];
        }    
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for(int i = 0; i < vec.size(); i++){
            int val1 = vec[i];
            int val2 = (*this)[i];
            sum += val1 * val2;
        }
        return sum;
    }
    int& operator[](const int i){
        return valAtIndex[i];
    }
    int size() const {
        return length;
    }

};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);