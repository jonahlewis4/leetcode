class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        for(int i = 1; i < complexity.size(); i++) {
            if(complexity[i] <= complexity.front()) {
                return 0;
            }
        }

        long long res = 1;
        int MOD = (int)(1e9) + 7;
        for(int i = 2; i <= complexity.size() - 1; i++){
            res *= i;
            res %= MOD;
        }

        return res;
    }
};