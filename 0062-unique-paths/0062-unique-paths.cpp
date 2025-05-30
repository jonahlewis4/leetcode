class Solution {
public:
    int uniquePaths(int m, int n) {
        int h = n - 1;
        int v = m - 1;

        int limiter = max(h, v);
        int nonLimiter = min(h, v);
        long long res = 1;
        int top = h + v;
        int right = 1;
        while(top > limiter) {
            res *= top;
            top--;
            if(right <= nonLimiter){
                res /= right;
            }
            right++;
            
        }

        return res;

        

    }

    
};