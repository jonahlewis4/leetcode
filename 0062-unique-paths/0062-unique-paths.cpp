class Solution {
private:
    int NcR(int n, int r) {
        r = min(r, n - r);
        unsigned long res = 1;
        for(int i = 1; i <= r; i++) {
            res *= n;
            n--;
            res /= i;
        }
        return res;
    }
public:
    int uniquePaths(int m, int n) {
        return NcR(m + n - 2, m - 1);
    }
};