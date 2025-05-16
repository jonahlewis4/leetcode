class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;

        sub.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            //find first number >= num.
            auto lb = lower_bound(sub.begin(), sub.end(), num);

            //if at the end push it back
            if(lb == sub.end()){
                sub.push_back(num);
            } else /*otherwise replace the one at that position with that value */ {
                int index = lb - sub.begin();
                sub[index] = num;
            }
        }

        return sub.size();

        
    }
};