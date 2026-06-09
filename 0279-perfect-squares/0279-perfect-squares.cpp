class Solution {
private:
    unordered_map<int, int> cache;
public:
    int numSquares(int n) {
        if(n == 0) {
            return 0;
        }
        
        if(cache[n]) {
            return cache[n];
        }

        int best = n;
        for(int i = 1; i * i <= n; i++) {
            int square = i * i;
            int attempt = numSquares(n - square);

            best = min(best, attempt + 1);
        }
        cache[n] = best;
        return best;
    }
};