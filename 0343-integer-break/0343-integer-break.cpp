class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }

        vector<int> c(n + 1);
        c[2] = 2;
        c[1] = 1;
        c[3] = 3;
        for(int i = 4; i <= n; i++) {
            int best = 0;
            for(int j = 1; j < i; j++) {
                int k = i - j;
                int product = c[k] * c[j];
                best = max(best, product);
            }
            c[i] = best;
        }
        return c.back();

        // c.resize(n, 0);
        // int best = 0;
        // for(int i = 1; i < n; i++) {
        //     int remaining = n - i;
        //     int sub = h(remaining);
        //     int product = i * sub;
        //     best = max(product, best);
        // }

        // return best;
    }
};