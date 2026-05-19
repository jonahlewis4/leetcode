class Solution {
    static bool isPrime(int set) {
        return set == 2 ||
               set == 3 ||
               set == 5 ||
               set == 7 ||
               set == 11||
               set == 13||
               set == 17||
               set == 19;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int total = 0;
        for(int i = left; i <= right; i++) {
            int set = __builtin_popcount(i);
            if(isPrime(set)) {
                total++;
            }
        }
        return total;
    }
};