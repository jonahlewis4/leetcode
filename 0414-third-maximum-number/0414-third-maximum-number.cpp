class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int nm = 1;
        int last = nums.back();
        for(int i = nums.size()  - 2; i >= 0; i--){
            int num = nums[i];
            if(num != last) {
                nm++;
                last = num;
            }

            if(nm == 3) {
                break;
            }
        }

        if (nm != 3) {
            return nums.back();
        }

        return last;
    }
};