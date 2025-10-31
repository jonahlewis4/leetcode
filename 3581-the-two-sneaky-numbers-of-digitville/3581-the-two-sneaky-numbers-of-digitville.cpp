class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != i && nums[nums[i]] != nums[i]){
                swap(nums[nums[i]], nums[i]);
            }
        }


        return {nums.back(), *(nums.end() - 2)};
    }

};