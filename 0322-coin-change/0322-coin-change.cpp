class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        while(true){
            vector<int> newDp = dp;
            bool progression = false;
            for(const auto & coin : coins){
                for(unsigned int i = 0; i < dp.size(); i++){
                    if(dp[i] != INT_MAX){
                        unsigned int newIndex = i + coin;
                        if(newIndex < newDp.size()){
                            if(newDp[newIndex] == INT_MAX){
                                progression = true;
                            }

                            
                            newDp[newIndex] = min(dp[i] + 1, newDp[newIndex]);
                            
                            
                        }
                    }
                }
            }
            if(newDp.back() != INT_MAX){
                return newDp.back();
            }
            if(!progression){
                return -1;
            }
            dp = newDp;
        }
        return -1;
    }
};