class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }

        int twoAgo = 0;
        int oneAgo = 0;
        int cur;
        for(int i = nums.size() - 1; i >= 1; i--){
            int amount = nums[i];
            int skip = oneAgo;
            int rob = amount + twoAgo;
            cur = max(skip, rob);
            twoAgo = oneAgo;
            oneAgo = cur; 
        }
        int no1 = cur;

        twoAgo = 0;
        oneAgo = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            int amount = nums[i];
            int skip = oneAgo;
            int rob = amount + twoAgo;
            cur = max(skip, rob);
            twoAgo = oneAgo;
            oneAgo = cur; 
        }
        int noFinal = cur;

        int res = max(no1, noFinal);
        return res;
    }
};