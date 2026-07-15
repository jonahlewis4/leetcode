class Solution {
    const vector<int>& nums;
    vector<int> res;
public:
    Solution(vector<int>& nums)  : nums(nums){
        res.resize(nums.size());
    }
    
    vector<int> reset() {
        res = nums;
        return res;
    }
    
    vector<int> shuffle() {
        res.resize(0);
        vector<int> is(nums.size());

        iota(is.begin(), is.end(), 0);

        while(!is.empty()) {
            int randIndex = rand()%is.size();
            res.push_back(nums[is[randIndex]]);
            swap(is[randIndex], is.back());
            is.pop_back();
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */