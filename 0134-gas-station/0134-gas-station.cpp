class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for(int i = 0; i < gas.size(); i++) {
            gas[i] = gas[i] - cost[i];
            sum += gas[i];
        }

        if(sum < 0) {
            return -1;
        }

        //find start of maximum continuous sum

        int maxSum = -1;
        int curSum = 0;
        int bestStart = -1;
        int curStart = 0;
        for(int i = 0; i < gas.size() * 2; i++) {
            int idx = i % gas.size();
            curSum += gas[idx];
            if(curSum < 0) {
                curSum = 0;
                curStart = idx + 1;
            }

            if(curSum > maxSum) {
                bestStart = curStart;
                maxSum = curSum;
            }
        }

        return bestStart;
    }
};