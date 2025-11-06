class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        stk.push(preorder.front());
        int smol = INT_MIN;
        for(int i = 1; i < preorder.size(); i++) {
            if(preorder[i] <= smol){
                return false;
            }
            
            while(!stk.empty() && stk.top() < preorder[i]){
                smol = stk.top();
                stk.pop();
            }
            stk.push(preorder[i]);

            
        }
        return true;
    }
};