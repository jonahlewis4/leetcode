class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroRight = 0;
        int twoLeft = nums.size() - 1;




        for(int i = zeroRight; i <= twoLeft; i++){
            if(nums[i] == 0){
                std::swap(nums[i], nums[zeroRight]);
                zeroRight++;
            } else if (nums[i] == 2){
                std::swap(nums[i], nums[twoLeft]);
                twoLeft--;
                i--;
            }
        }
        
    }
};