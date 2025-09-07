class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);

        for(int i = 0; i < n / 2; i++) {
            res[i * 2] = i + 1;
            res[i * 2 + 1] = -(i + 1);
        }

        if(n % 2 == 1) {
            res.back() = 0;
        }

        return res;
    }
};