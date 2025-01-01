class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++){
            res[i] = num1s(i);
        }
        return res;
    }
    int num1s(int n){
        int num1s = 0;
        while( n > 0){
            n = n & (n - 1);
            num1s++;
        }
        return num1s;
    }
};