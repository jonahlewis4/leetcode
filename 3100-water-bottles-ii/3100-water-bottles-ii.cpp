class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int used = 0;
        while(true) {
            int afterExchange = numBottles - numExchange;
            if(afterExchange < 0) {
                return used + numBottles;
            }
            used += numExchange;
            numBottles -= numExchange;
            numBottles++;
            numExchange++;
        }
    }
};