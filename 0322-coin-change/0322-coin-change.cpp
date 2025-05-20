class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> minCoinsToReach;
        minCoinsToReach[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(const auto & coin : coins){
                if(minCoinsToReach.find(i - coin) != minCoinsToReach.end()){
                    if(minCoinsToReach.find(i) == minCoinsToReach.end()){
                        minCoinsToReach[i] = amount;
                    }

                    minCoinsToReach[i] = min(minCoinsToReach[i], minCoinsToReach[i - coin] + 1);
                }
            }
        }

        if(minCoinsToReach.find(amount) == minCoinsToReach.end()){
            return -1;
        }
        return minCoinsToReach[amount];
    }
};