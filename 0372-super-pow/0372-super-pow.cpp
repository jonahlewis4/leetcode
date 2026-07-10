class Solution {
private:
    static int modPow(int a, int power) {
        a %= 1337;
        if(power == 0) {
            return 1;
        }
        int runningPower = 1;
        int runningResult = a;
        while(runningPower != power) {
            runningResult *= runningResult;
            runningResult %= 1337;

            runningPower *= 2;

            if(runningPower * 2 > power) {
                int difference = power - runningPower;
                int subPow = modPow(a, difference);
                return (subPow * runningResult) % 1337;
            }
        }
        return runningResult;
    }
public:
    int superPow(int a, vector<int>& b) {
        int oldA = a;
        a = modPow(a, b.front());
        for(int i = 1; i < b.size(); i++) {
            a = modPow(a, 10);
            int digit = b[i];
            int next = modPow(oldA, digit);
            a = (a * next) % 1337;
        }

        return a;
    }
};