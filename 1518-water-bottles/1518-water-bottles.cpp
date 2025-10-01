class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int used = 0;
        while(numBottles > 0) {
            if(numBottles - numExchange < 0) {
                return used + numBottles;
            }
            numBottles -= numExchange;
            
            numBottles++;
            used += numExchange;
        }
        return used;
    }
};