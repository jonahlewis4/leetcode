class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int best = INT_MIN;
        stack<int> stack;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] < best) {
                return true;
            }
            while(!stack.empty() && nums[i] > stack.top()) {
                best = stack.top();
                stack.pop();
            }
            if(nums[i] > best) {
                stack.push(nums[i]);
            }
        }

        return false;
    }
};