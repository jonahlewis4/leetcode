
class Solution {
private:
    static int binomial_coefficient(int n, int k){
        if(k == 0) {
            return 1;
        }
        double res = 1;
        int kStart = k;
        while(k > 0) {
            res =  res * n / (kStart - k + 1);
            n--;
            k--;
        }
        return res + .5;
    }
public:
    int uniquePaths(int m, int n) {
        return binomial_coefficient(m + n - 2, m - 1);
    }
};