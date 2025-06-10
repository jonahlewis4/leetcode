class Solution {
public:
    int uniquePaths(int m, int n) {
        int denom = min(m, n) - 1;
        int numerator = (m + n) - 2;
        int mulEnd = numerator - denom;
        long long res = 1;
        for(int i = numerator; i > mulEnd; i--){
            res *= i;
            res /= (numerator - i + 1);
        }
        
        return res;
    }
};