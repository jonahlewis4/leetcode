class Solution {
       void getDivisors(int num, vector<int>& res) {
            if(num == 1) {
                return;
            }
            res.push_back(1);
            for(int i = 2; i * i <= num; i++){
                if(num % i == 0) {
                    res.push_back(i);
                    if(num/i != i) {
                        res.push_back(num / i);

                    }
                }
            }
        }
public:
    bool checkPerfectNumber(int num) {
        vector<int> divisors;
        getDivisors(num, divisors);
        int sum = accumulate(divisors.begin(), divisors.end(), 0);
        return sum == num;
    }
};