class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(parity(nums[i]) == parity(nums[i - 1])){
                return false;
            }
        }
        return true;
    }

    bool parity(int n){
        return n & 1 == 1;
    }
};