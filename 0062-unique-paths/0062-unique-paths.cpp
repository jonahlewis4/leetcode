class Solution {
public:
    static int uniquePaths(int m, int n) {
        m--;
        n--;
        int sum = m + n;
        int choose = n;
        return comb(sum, choose);
    }

    static int comb(unsigned int total, unsigned int choose) {
        unsigned long ans = 1;
        choose = max(total - choose, choose);
        unsigned int bot = 1;
        for(unsigned int i = choose + 1; i <= total; i++){
            ans *= i;
            ans /= bot;
            bot++;
        }
        return ans;
    }

};