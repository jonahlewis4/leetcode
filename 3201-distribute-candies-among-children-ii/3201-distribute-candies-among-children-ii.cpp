class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(limit, n); i++){
            int m = n - i;

            //if m > limit * 2 continue because it cannot be split
            if(m > limit * 2) {
                continue;
            }

            int atMost = min(limit, m);
            int atLeast = max(0, m - limit);
            ans += atMost - atLeast  + 1;
            
        }
        return ans;
    }
};