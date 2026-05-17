class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size());
        stack<int> stk;
        for(int i = prices.size() - 1; i >= 0; i--) {
            while(!stk.empty() && stk.top() > prices[i]) {
                stk.pop();
            }
            res[i] = prices[i];
            if(!stk.empty()){
                res[i] -= stk.top();
            }
            stk.push(prices[i]);
        }
        return res;
    }
};