class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i - 1 >= 0 && nums[i - 1] >= nums[i]){
            i--;
        }
        if(i - 1 < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        int replaced = nums[i];

        int j = nums.size() - 1;
        while(j >= 0 && nums[j] <= replaced){
            j--;
        }
        int firstLarger = nums[j];

        nums[i] = firstLarger;

        int distance = (nums.size() - 1 - i)/2 ;
        for(int k = nums.size() - 1; k >= nums.size() - distance && k >= 0; k--){
            int match = i + nums.size() - k;
            swap(nums[match], nums[k]);
        }

        
        nums[ i + nums.size() - j] = replaced;
    }
};