class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(limit, n); i++){
            int m = n - i;

            if(m <= limit) {
                ans += m + 1;
                continue;
            }

            int upperRemoved = m - limit;
            int lowerRemoved = m - limit;
            if(upperRemoved > (m + 1) / 2) {
                upperRemoved = (m + 1) / 2;
            }
            if(lowerRemoved > (m + 1) / 2){
                if((m + 1) % 2 == 1){
                    lowerRemoved = (m + 1) / 2 + 1;
                } else {
                    lowerRemoved = (m + 1) / 2;
                }
            }
            int additions = m + 1 - lowerRemoved - upperRemoved;
            ans += additions;
            
        }
        return ans;
    }
};