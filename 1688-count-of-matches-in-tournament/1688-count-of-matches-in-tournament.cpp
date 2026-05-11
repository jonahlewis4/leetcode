class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n > 0) {
            matches += n / 2;
            if(n % 2 == 0) {
                n /= 2;
            } else if (n > 1){
                n = n / 2 + 1;
            } else if (n == 1) {
                n = 0;
            }
        }
        return matches;
    }
};