class Solution {
    class Recursive {
        double res = 0;
        int n;
        int k;
        int maxPts;
    public:
        Recursive(int n, int k, int maxPts) : n(n), k(k), maxPts(maxPts) {}
        double calc() {
            recurse(0, 1);
            return res;
        }
        void recurse(int sum, double chance) {
            if(sum >= k) {
                if(sum <= n) {
                    res += chance;
                }
                return;
            }
            for(int i = 1; i <= maxPts; i++) {
                recurse(sum + i, chance / (double)maxPts);
            }
        }
    };
    class Memo {
        int n;
        int k;
        int maxPts;
        unordered_map<int, double> cache;
    public:
        Memo(int n, int k, int maxPts) : n(n), k(k), maxPts(maxPts) {}
        double calc() {
            return recurse(0);
        }
        double recurse(int sum) {
            if(cache.find(sum) != cache.end()) {
                return cache[sum];
            }
            if(sum >= k) {
                if(sum <= n) {
                    cache[sum] = 1;
                } else {
                    cache[sum] = 0;
                }
                return cache[sum];
            }
            double total = 0;
            for(int i = 1; i <= maxPts; i++) {
                double chan = recurse(sum + i);
                total += chan;
            }
            double ans = total / maxPts;
            cache[sum] = ans;
            return ans;
        }
    };

    
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + maxPts);
        for(int i = n + 1; i < dp.size(); i++) {
            dp[i] = 0;
        }
        for(int i = k; i <= n; i++) {
            dp[i] = 1;
        }
        for(int i = k - 1; i >= 0; i--) {
            double total = 0;
            if(i == k - 1) {
                for(int card = 1; card <= maxPts; card++) {
                    int next = i + card;
                    double prob = dp[next];
                    total += prob;
                }
                total /= maxPts;
                dp[i] = total;
            } else {
                total = dp[i + 1] * maxPts;
                total -= dp[i + maxPts + 1];
                total += dp[i + 1];
                total /= maxPts;
                dp[i] = total;
            }
        }
        return dp.front();
    }
};