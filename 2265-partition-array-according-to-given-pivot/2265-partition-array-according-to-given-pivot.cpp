class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(), pivot);
        int lessI = 0;
        int greaterI = ans.size() - 1;
        for(int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if(nums[i] < pivot) {
                ans[lessI] = nums[i];
                lessI++;
            }
            if(nums[j] > pivot) {
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }

        return ans;
    }
};