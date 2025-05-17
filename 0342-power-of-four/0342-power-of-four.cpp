class Solution {

    static vector<int> powers;
public:
    Solution() {
        long power = 1;
        while(power < INT_MAX){
            powers.push_back(power);
            power *= 4;
        }
    }

    bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }

        while(n % 4 == 0){
            n/=4;
        }
        return n == 1;
    }
};
vector<int> Solution::powers = {};