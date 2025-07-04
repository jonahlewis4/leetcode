class Solution {
private:
    static int log2KFloor(long long k) {
        return 63 - __builtin_clzll(k);
    }
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int ans = 0;
        while(k > 0) {
            int operationToGetHere = log2KFloor(k);
            ans += operations[operationToGetHere];
            k -= (1ll << operationToGetHere);
        }
        return ans % 26 + 'a';
    }
};