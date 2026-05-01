class Solution {
public:
    int xorOperation(int n, int start) {
        //    0
        //    1
        //   10
        //  100
        // 1000

        //   11 3 + 0
        //  101 3 + 2
        //  111 3 + 4
        // 1001 3 + 6
        // 1011 3 + 8

        int res = 0;
        for(int i = 0; i < n; i++) {
            int val = i * 2 + start;
            res ^= val;
        }
        return res;
    }
};