class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        for(int i = 1; i < nums.size(); i++) {
            int prev = nums[i-1];
            int& cur = nums[i];
            if(cur <= prev) {
                operations += prev - cur + 1;
                cur = prev + 1;
            }
        }
        return operations;

        
    }
};