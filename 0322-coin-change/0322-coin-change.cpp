class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        constexpr int NOT_REACHED = INT_MAX;
        vector<int> minCoinsToReach(amount + 1, NOT_REACHED);
        minCoinsToReach[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(const auto & coin : coins){
                if(i - coin < 0 ){
                    continue;
                }
                if(minCoinsToReach[i - coin] != NOT_REACHED){
                    minCoinsToReach[i] = min(minCoinsToReach[i], minCoinsToReach[i - coin] + 1);
                }
            }
        }

        if(minCoinsToReach[amount] == NOT_REACHED){
            return -1;
        }
        return minCoinsToReach[amount];
    }
};