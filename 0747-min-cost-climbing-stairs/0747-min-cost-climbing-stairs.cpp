#include <algorithm>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int  oneAgo = 0;
        int twoAgo = 0;
        for(int i = cost.size() - 1; i >= 0; i--){
            int lessExpensive = std::min(oneAgo, twoAgo);
            int localCost = cost[i] + lessExpensive;
            twoAgo = oneAgo;
            oneAgo = localCost;
        }
        return std::min(oneAgo, twoAgo);
    }
};