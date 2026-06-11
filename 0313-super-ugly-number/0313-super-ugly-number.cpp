class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<pair<long long, int>> dp(n);
        vector<int> primePtrs(primes.size(), 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dp.front() = {1, -1};
        for(int i = 0; i < primes.size(); i++) {
            pq.push({(long long)primes[i], i});
        }

        for(int i = 1; i < n; i++) {
            auto [uglyNum, primeIdx] = pq.top();
            pq.pop();
            dp[i] = {uglyNum, primeIdx};
            
            primePtrs[primeIdx]++;
            while(dp[primePtrs[primeIdx]].second > primeIdx){
                primePtrs[primeIdx]++;
            }

            pq.push({dp[primePtrs[primeIdx]].first * primes[primeIdx], primeIdx});
        }
        
        return dp.back().first;
    }
};