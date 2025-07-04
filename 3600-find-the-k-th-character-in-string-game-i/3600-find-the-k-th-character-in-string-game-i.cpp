class Solution {
private:
    static int log2KFloor(int k) {
        return 31 - __builtin_clz(k);
    }
public:
    char kthCharacter(int k) {
        k--;
        int ans = 0;
        while(k > 0) {
            int operationToGetHere = log2KFloor(k);
            ans ++;
            k -= (1 << operationToGetHere);
        }
        return ans % 26 + 'a';
    }
};