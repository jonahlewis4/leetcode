class Solution {
    static bool isPrime(int n) {
        if(n < 2) {
            return false;
        }
        for(int i = 2; (long long)i * i <= n; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
    static bool check(int i, int n) {
        if(n % i != 0) {
            return true;
        }
        int other = n / i;
        if(other > i) {
            if(!check(other, n)) {
                return false;
            }
        }

        if(i == 2 || i == 3 || i == 5) {
            return true;
        }

        if(isPrime(i)) {
            return false;
        }
        return true;
    }
public:
    bool isUgly(int n) {
        if(n <= 0) {
            return false;
        }
        
        for(int i = 1; i * i <= n; i++) {
            if(!check(i, n)){
                return false;
            }
        }
        return true;
    }
};