class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;

        int endMin = 0;
        int minSum = gas.front() - cost.front();

        for(int i = 0; i < gas.size(); i++) {
            int change = gas[i] - cost[i];
            sum += change;
            if(sum < minSum) {
                minSum = sum;
                endMin = i;
            }
        }

        if(sum < 0) {
            return -1;
        }

        return (endMin + 1) % gas.size();
    }
};