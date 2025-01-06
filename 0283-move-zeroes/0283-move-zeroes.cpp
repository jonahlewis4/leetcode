class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        
        int numZeroes = 0;

     
        while(true){
            
            while(l < nums.size() && nums[l] != 0){
                l++;
            }
            r = l;
            while(r < nums.size() - numZeroes && nums[r] == 0){
                r++;
            }
            if(r >= nums.size() || l >= nums.size() || l > r){
                break;
            }
            std::swap(nums[l], nums[r]);
        }
    }
};