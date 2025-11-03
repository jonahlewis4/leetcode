class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int previousIdx = 0;
        int total = 0;
        for(int i = 1; i < colors.size(); i++) {

            int nextColor = colors[i];
            int prevColor = colors[previousIdx];

            if(nextColor != prevColor) {
                previousIdx = i;
                continue;
            }

            int nextCost = neededTime[i];
            int prevCost = neededTime[previousIdx];

            if(nextCost > prevCost) {
                total += prevCost;
                previousIdx = i;
            } else {
                total += nextCost;
            }
        }

        return total;

    }
};