class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int previousIdx = -1;
        int total = 0;
        for(int i = 0; i < colors.size(); i++) {
            if(previousIdx < 0){
                previousIdx = i;
                continue;
            }

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