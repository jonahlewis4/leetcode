class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(stk.empty() || num < nums[stk.top()]){
                stk.push(i);
            }
        }
        int maxWidth = 0;
        for(int i = nums.size() - 1; i >= 1; i--){
            while(!stk.empty() && nums[stk.top()] <= nums[i]){
                maxWidth = max(maxWidth, i - stk.top());
                stk.pop();
            }
        }
        return maxWidth;

    }
};