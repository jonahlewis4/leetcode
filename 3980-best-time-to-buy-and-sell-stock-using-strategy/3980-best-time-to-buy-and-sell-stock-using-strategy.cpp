class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long profit = 0;
        int l = 0;
        int r = 0;
        long long bestProfit = 0;
        int bestStart = 0;

        for(int i = 0; i < k / 2; i++) {
            if(strategy[i] < 0) {
                profit += prices[i];
            }
            if(strategy[i] > 0) {
                profit -= prices[i];
            }
        }
        for(int i = k / 2; i < k; i++) {
            if(strategy[i] == 0) {
                profit += prices[i];
            }
            if(strategy[i] == -1) {
                profit += prices[i] * 2;
            }
        }
        if(profit > bestProfit) {
            bestStart = l;
            bestProfit = profit;
        }
        l++;
        r = k;
        while(r < prices.size()) {
            if(strategy[l - 1] == -1) {
                profit -= prices[l - 1];
            }
            if(strategy[l - 1] == 1) {
                profit += prices[l - 1];
            }
            
            int choppedI = l + k / 2 - 1;
            profit -= prices[choppedI];
            if(strategy[r] == 0) {
                profit += prices[r];
            }
            if(strategy[r] == -1) {
                profit += prices[r] * 2;
            }
            if(profit > bestProfit) {
                bestStart = l;
                bestProfit = profit;
            }    
            l++;
            r++;
        }
        long long res = 0;
        long long noChange = 0;
        for(int i = 0; i < prices.size(); i++){
            if(i >= bestStart && i < bestStart + k){
                if(i < bestStart + (k / 2)) {
                    
                } else {
                    res += prices[i];
                }
            } else {
                res += strategy[i] * prices[i];
            }
            noChange += strategy[i] * prices[i];
        }

        return max(noChange, res);
    }
};