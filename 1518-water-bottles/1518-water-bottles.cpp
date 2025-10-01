class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int used = 0;
        while(true) {
            int changeAble = numBottles / numExchange;
            if(changeAble == 0) {
                return used + numBottles;
            }
            used += numExchange * changeAble;
            numBottles -= numExchange * changeAble;
            numBottles += changeAble;
        }
        return used;
    }
};