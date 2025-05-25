class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n <= k && m <= k){
            return 0;
        }

        int largerLog = max(n, m);

        return (long long)k * (largerLog - k);
    }
};