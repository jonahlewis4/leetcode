class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int smol = cost.front();
        for(int& i : cost) {
            smol = min(smol, i);
            i = smol;
        }

        return cost;
    }
};