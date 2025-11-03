class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<int> stk;
        int total = 0;
        for(int i = 0; i < colors.size(); i++) {
            if(stk.empty()){
                stk.push(i);
                continue;
            }

            int nextColor = colors[i];
            int prevColor = colors[stk.top()];

            if(nextColor != prevColor) {
                stk.push(i);
                continue;
            }

            int nextCost = neededTime[i];
            int prevCost = neededTime[stk.top()];

            if(nextCost > prevCost) {
                total += prevCost;
                stk.pop();
                stk.push(i);
            } else {
                total += nextCost;
            }
        }

        return total;

    }
};