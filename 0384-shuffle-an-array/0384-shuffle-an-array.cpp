class Solution {
    const vector<int>& nums;
    vector<int> res;
public:
    Solution(vector<int>& nums)  : nums(nums){
        res = nums;
    }
    
    vector<int> reset() {
        res = nums;
        return res;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < res.size(); i++) {
            int idx = i + rand() % (res.size() - i);
            swap(res[idx], res[i]);
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