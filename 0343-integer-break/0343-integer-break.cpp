class Solution {
    vector<int> c;
    int h(int n) {
    
        if(c[n]){
            return c[n];
        }

        int best = n;
        for(int i = 1; i < n; i++) {
            int remaining = n - i;
            int sub = h(remaining);
            int product = i * sub;
            best = max(product, best);
        }

        c[n] = best;
        return best;
    }
public:
    int integerBreak(int n) {
        c.resize(n, 0);
        int best = 0;
        for(int i = 1; i < n; i++) {
            int remaining = n - i;
            int sub = h(remaining);
            int product = i * sub;
            best = max(product, best);
        }

        return best;
    }
};