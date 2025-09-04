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

        int curTank = 0;
        int bestStart = 0;
        for(int i = 0; i < gas.size(); i++) {
            int idx = i % gas.size();
            curTank += gas[idx];
            if(curTank < 0) {
                bestStart = i + 1;
                curTank = 0;
            }
        }

        return bestStart;
    }
};