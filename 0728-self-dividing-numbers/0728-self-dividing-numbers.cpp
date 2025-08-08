class Solution {
public:
    vector<int> selfDividingNumbers(int lefti, int right) {
        vector<int> res = {};
        for(int left = lefti; left <= right; left++){
            if(isSelfDividing(left)){
                res.push_back(left);
            }
        }
        return res;
    }
    static bool isSelfDividing(int num) {
        int originalNum = num;
        while(num > 0){
            int dig = num % 10;
            if(dig == 0) {
                return false;
            }
            if(originalNum % dig != 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
};