class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack;

        vector<int> res(nums.size(), -1);
        for(int i = 0; i < nums.size() * 2; i++) {
            int idx = i % nums.size();

            while(!stack.empty() && nums[stack.top()] < nums[idx]){
                res[stack.top()] = nums[idx];
                stack.pop();
            }
            if(i == idx) {
                stack.push(idx);
            }
        }


        return res;

    }
};