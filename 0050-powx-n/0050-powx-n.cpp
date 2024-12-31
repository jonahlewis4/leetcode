class Solution {
public:
    double myPow(double x, int n) {
        std::unordered_map<int, double> cache;
        double beforeNegativeResolution = dfs(x, abs(long(n)), cache);
        if(n < 0){
            return 1/beforeNegativeResolution;
        }
        return beforeNegativeResolution;

        //call with n as abs.
    }
    double dfs(double x, long n, std::unordered_map<int, double> &cache){
        if(cache.find(n) != cache.end()){
            return cache[n];
        }
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        if(n % 2 == 0){
            double half = dfs(x, n / 2, cache);
            double ans = half * half;

            cache[n] = ans;
            return ans;
        } else {
            double halfP1 = dfs(x, (n/2) + 1, cache);
            double half = dfs(x, n/2, cache);
            double ans = half * halfP1;
            cache[n] = ans;
            return ans;
        }

    }
};