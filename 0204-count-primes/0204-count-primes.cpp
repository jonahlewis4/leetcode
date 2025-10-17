class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 0;
        }
        vector<bool> candidates(n, true);
        candidates.front() = false;
        candidates[1] = false;

        for(int i = 2; i * i < n; i++) {
            if(candidates[i]){
                for(int j = i * i; j < n; j+=i){
                    candidates[j] = false;
                }
            }
        }

        int primeCount = 0;
        for(const bool isPrime : candidates) {
            if(isPrime){
                primeCount++;
            }
        }
        return primeCount;
    }
};