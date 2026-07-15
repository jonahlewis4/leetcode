class Solution {
    vector<int> c;
    int r(vector<int>& nums, int target) {
        if(target == 0) {
            return 1;
        }

        if(c[target] != -1){
            return c[target];
        }

        int sum = 0;
        for(int num : nums) {
            if(target - num < 0) {
                continue;
            }

            sum += r(nums, target - num);
        }
        c[target] = sum;
        return sum;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        c.resize(target + 1, -1);
        return r(nums, target);
        
    }
};