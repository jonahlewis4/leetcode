class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(const auto & num : nums) {
            freq[num]++;
        }

        for(const auto & [_, val] : freq) {
            if(isPrime(val)){
                return true;
            }
        }

        return false;

    }

    bool isPrime(int n) const {
        if(n == 0){
            return false;
        }
        if(n == 1) {
            return false;
        }
        if(n == 2) {
            return true;
        }

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
};