class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int falls = 0;
        for(int i = 1; i < nums.size(); i++) {
            int prev = nums[i-1];
            int cur = nums[i];
            
            if(cur >= prev){
                continue;
            }

            falls++;

            if(falls > 1){
                return false;
            }
            
            //if no 2 ago or 2 ago lte, set 1 ago to cur
            //if 2 ago g, set cur to 1 ago
            
            bool twoAgoExists = i - 2 >= 0;
            int twoAgo;
            if(twoAgoExists){
                twoAgo = nums[i-2];
            }

            if(!twoAgoExists || twoAgo <= cur){
                nums[i-1]=cur;
            } else {
                nums[i] = nums[i-1];   
            }
            
        }
        return true;
    }
};