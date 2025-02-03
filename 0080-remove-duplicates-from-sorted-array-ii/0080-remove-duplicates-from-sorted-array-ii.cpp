class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 0 0 2 2 4 4 4 5 5 5
        int l = 1;
        int r = 1;
        int curNum = nums[0];
        int curNumCount = 0;
        int count = 1;
        while(r < nums.size()){
            if(nums[r] == nums[r - 1]){
                count++;
                if(count > 2){
                    r++;
                    continue;
                }
            } else {
                count = 1;
            }
            //std::swap(nums[l], nums[r]);
            nums[l] = nums[r];
            r++;
            l++;
        }
        return l;
    }
};