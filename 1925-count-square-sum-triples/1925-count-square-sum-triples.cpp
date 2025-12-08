class Solution {
    static bool isPerfectSquare(int n) {
        for(int i = 1; i * i <= n; i++) {
            if(i * i == n) {
                return true;
            }
        }

        return false;
    }
public:
    int countTriples(int n) {
        int count = 0;
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b * b + a * a <= n * n; b++) {
                int cSquared = b * b + a * a;
                int c = sqrt(cSquared);

                if(c * c == cSquared) {
                    count++;
                }
            }
        }

        return count;
    }
};