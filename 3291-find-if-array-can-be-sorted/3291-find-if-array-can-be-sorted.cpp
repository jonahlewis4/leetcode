class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        //bubble sort but we also need to check if swaps are allowed
        for(int i = 1; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] > nums[j + 1]){
                    if(cannotSwap(nums[j], nums[j + 1])){
                        return false;
                    }
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return true;
    }
    bool cannotSwap(int a, int b){
        return __builtin_popcount(a) != __builtin_popcount(b);
    }
};