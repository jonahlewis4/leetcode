class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> stk;
        stk.push(0);
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] < stk.top()){
                stk.pop();
            }

            if(stk.top() != nums[i]) {
                res++;
                stk.push(nums[i]);
            }
        }

        return res;

    }
};