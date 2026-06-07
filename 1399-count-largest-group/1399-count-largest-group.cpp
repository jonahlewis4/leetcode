class Solution {
private:
    static int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> sums;
        for(int i = 1; i <= n; i++) {
            sums[digitSum(i)]++;
        }

        int best = 0;
        int count = 0;
        for(auto [sum, amount] : sums) {
            if(amount > best){
                best = amount;
                count = 1;
            } else if (amount == best) {
                count++;
            }
        }
        return count;
    }
};