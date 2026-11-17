class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        unsigned int product = 1;
        
        if(k == 0) {
            return 0;
        }
        
        int total = 0;
        while(r < nums.size()){
            product *= nums[r];
            while(l <= r && product >= k) {
                product /= nums[l];
                l++;
            }
            
            total += r - l + 1;
            r++;
        }
        return total;
    }
};