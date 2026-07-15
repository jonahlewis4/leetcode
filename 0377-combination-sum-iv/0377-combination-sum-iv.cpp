class Solution {
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> c(target + 1);
        c.front() = 1;
        for(int i = 1; i <= target; i++) {
            unsigned int sum = 0;
            for(const int num : nums) {
                if(i - num < 0) {
                    continue;
                }
                sum += c[i - num];
            }
            c[i] = sum;
        }
        return c.back();
        
    }
};