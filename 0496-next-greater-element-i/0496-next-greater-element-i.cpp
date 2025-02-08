class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreatest;
        std::stack<int> stack;

        for(int i = 0; i < nums2.size(); i++){
            while(!stack.empty() && stack.top() < nums2[i]){
                int top = stack.top();
                stack.pop();
                nextGreatest[top] = nums2[i];
            }
            stack.push(nums2[i]);
        }

        while(!stack.empty()){
            nextGreatest[stack.top()] = -1;
            stack.pop();
        }

        vector<int> res(nums1.size());

        for(int i = 0; i < nums1.size(); i++){
            res[i] = nextGreatest[nums1[i]];
        }
        return res;
    }
};