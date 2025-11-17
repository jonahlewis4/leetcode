class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last1 = -k - 1;
        for(int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            if(cur == 1) {
                if(last1 + k >= i){
                    return false;
                }
                last1 = i;
            }
        }
        return true;
    }
};