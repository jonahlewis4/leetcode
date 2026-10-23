class Solution {
    int n;
    int maskLen = 4;
    
    int extract(int needs, int i) {
        int mask = (1 << (maskLen)) - 1;
        int shiftMask = mask << (i * maskLen);
        int res = (needs & shiftMask);
        res >>= (i * maskLen);
        return res;
    }
    int insert(int needs, int i, int newValue) {
        int newValueMask = newValue << (i * maskLen);
        int curValue = extract(needs, i);
        needs ^= (curValue << (i * maskLen));
        needs |= newValueMask;
        return needs;
    }
    int r(vector<vector<int>>& special, int needs) {
        bool remaining = false;
        for(int i = 0; i < n; i++) {
            int curVal = extract(needs, i);
            if(curVal != 0) {
                remaining = true;
            }
        }

        
        int hashNeeds = needs;
        if(dp.contains(hashNeeds)) {
            return dp[hashNeeds];
        }
       
        if(!remaining) {
            return 0;
        }

        int best = INT_MAX;
        for(const vector<int>& offer : special) {
            int newNeeds = needs;

            bool overboard = false;
            for(int i = 0; i < offer.size() - 1; i++) {
                int decrease = offer[i];

                int curVal = extract(needs, i);
                int newVal = curVal - offer[i];
                
                if(newVal < 0) {
                    overboard = true;
                    break;
                } else {
                    newNeeds = insert(newNeeds, i, newVal);
                }
            }
            if(overboard) {
                continue;
            }
            int cost = offer.back();
            int totalCost = cost + r(special, newNeeds);
            best = min(best, totalCost);
        }
        dp[hashNeeds] = best;
        return best;
    }
    int manualPurchase(const vector<int>& offer, const vector<int>& price) {
        int total = 0;
        for(int i = 0; i < price.size(); i++){
            total += price[i] * offer[i];
        }
        return total;
    }

    bool exceeds(const vector<int>& offer, const vector<int>& needs) {
        for(int i = 0; i < needs.size(); i++) {
            if(offer[i] > needs[i]) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> prune(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector<vector<int>> res;
        for(const vector<int>& offer: special){
            if(manualPurchase(offer, price) < offer.back()) {
                continue;
            }
            if(exceeds(offer, needs)) {
                continue;
            }
            res.push_back(offer);
        }

        for(int i = 0; i < price.size(); i++) {
            vector<int> offer(price.size() + 1, 0);
            offer.back() = price[i];
            offer[i] = 1;
            res.push_back(offer);
        }
        return res;
    }
    unordered_map<int, int> dp;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        
        special = prune(price, special, needs);
        int needMask = 0;
        for(int i = 0; i < needs.size(); i++) {
            needMask = insert(needMask, i, needs[i]);
        }
        return r(special, needMask);
    }
};