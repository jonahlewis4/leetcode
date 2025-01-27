class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            long long nextIdx = (long long)nums[i] - 1;
            while(nextIdx >= 0 && nextIdx < nums.size() && nums[nextIdx] != nextIdx + 1){
                long long oldNext = (long long)nums[nextIdx] - 1;
                nums[nextIdx] = nextIdx + 1;
                nextIdx = oldNext;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};