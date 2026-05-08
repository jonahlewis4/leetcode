class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        while(num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        sort(digits.begin(), digits.end());

        const vector<int>& d = digits;
        vector<int> l;
        vector<int> r;
        return R(d, l, r, 0);
    }
    static int R(const vector<int>& d,
                 vector<int>& l,
                 vector<int>& r,
                 int i
    ){
        if(i >= 4) {
            if(l.size() > 0 && r.size() > 0) {
                return dSum(l) + dSum(r);
            } else {
                return INT_MAX;
            }
        }
        
        l.push_back(d[i]);
        int res1 = R(d,l,r,i + 1);
        l.pop_back();
        r.push_back(d[i]);
        int res2 = R(d,l,r,i + 1);
        r.pop_back();
        return min(res1, res2);
    }
    static int dSum(const vector<int>& v){
        int res = 0;
        for(const int num : v) {
            res *= 10;
            res += num;
        }
        return res;
    }
};