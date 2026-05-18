class Solution {
    static void r(const vector<int>& nums, int i, int sum, int& res){
        if(i >= nums.size()) {
            res += sum;
            return;
        }

        r(nums, i + 1, sum ^ nums[i], res);
        r(nums, i + 1, sum, res);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        r(nums, 0, 0, total);
        return total;
        
    }
};