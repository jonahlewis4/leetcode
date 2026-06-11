class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp{1};
        vector<int> primePtrs(primes.size(), 0);

        for(int i = 1; i < n; i++) {
            int best = INT_MAX;
            for(int j = 0; j < primes.size(); j++) {
                int ptr = primePtrs[j];
                long long prime = primes[j];
                long long candidate = dp[ptr] * prime;
                best = min(candidate, (long long)best);
            }

            dp.push_back(best);
            for(int j = 0; j < primes.size(); j++) {
                int& ptr = primePtrs[j];
                long long prime = primes[j];
                long long candidate = dp[ptr] * prime;
                if(candidate == best) {
                    ptr++;
                }
            }

        }
        
        return dp.back();
    }
};