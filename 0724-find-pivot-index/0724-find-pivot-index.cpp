class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(const auto & num : nums) {
            total += num;
        }

        int after = total - nums[0];
        int before = 0;

        for(int i = 0; i + 1 < nums.size(); i++) {
            if(after == before){
                return i;
            }
            before += nums[i];
            after -= nums[i + 1];
        }

        if(after == before) {
            return nums.size() - 1;
        }

        before += nums.back();
        


        return -1;
    }
};