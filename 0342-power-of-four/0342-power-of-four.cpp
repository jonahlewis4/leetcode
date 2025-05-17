class Solution {

    static unordered_set<int> powers;
public:
    Solution() {
        long power = 1;
        while(power < INT_MAX){
            powers.insert(power);
            power *= 4;
        }
    }

    bool isPowerOfFour(int n) {
        return powers.find(n) != powers.end();

    }
};
unordered_set<int> Solution::powers = {};