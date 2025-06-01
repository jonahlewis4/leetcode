class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(limit, n); i++){
            int remaining = n - i;

            if(remaining < 0){
                break;
            }

            int combs = remaining + 1 - max(0, remaining - limit) * 2;
            ans += max(combs, 0);
        }
        return ans;
    }
};