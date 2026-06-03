class Solution {
public:
    string generateTheString(int n) {
        string res(n, '.');
        res[0] = 'z';
        if(n == 1) {
            return res;
        }
        res[1] = 'x';
        for(int i = 2; i < n; i++) {
            if((i/2)%2 == 0) {
                res[i] = 'x';
            } else {
                res[i] = 'z';
            }
        }
        if(n % 2 == 1) {
            res.back() = 'y';
        }
        return res;
    
    }
};