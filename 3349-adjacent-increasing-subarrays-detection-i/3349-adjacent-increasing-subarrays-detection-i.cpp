class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        

        int l = 0;
        int m = 0;
        
        for(int r = 1; r < nums.size(); r++) {
            int prev = nums[r - 1];
            int current = nums[r];
            
            if(m - l < k) {
                l = m;
            }

            if(current <= prev) {
                //loss of streak
                if(m <= l){
                    m = r;
                } else {
                    l = m;
                    m = r;
                }
            }

            if((m <= l && r - l + 1 == 2 * k) || (m > l && m - l >=k && r - m + 1 >= k)){
                return true;
            }
        }



        return false;
    }
};