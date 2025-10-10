class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        if(k >= energy.size()) {
            return *min_element(energy.begin(), energy.end());
        }
        vector<int> dp(k);
        
        int best = INT_MIN;
        int dpI = 0;
        for(int i = energy.size() - 1; i > energy.size() - 1 - k; i--) {
            dp[dpI] = energy[i];
            best = max(dp[dpI], best);
            dpI++;
            dpI %= k;
        }

        for(int i = energy.size() - k - 1; i >= 0; i--) {
            int next = dp[dpI];
            int calc = next + energy[i];
            dp[dpI] = calc;
            best = max(calc, best);
            dpI++;
            dpI %= k;
        }

        return best;

        
    }
};