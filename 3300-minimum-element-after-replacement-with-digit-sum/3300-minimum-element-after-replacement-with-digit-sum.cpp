class Solution {
private:
    static int dSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int small = INT_MAX;
        for(const int num : nums) {
            int digSum = dSum(num);
            small = min(small, digSum);
        }
        return small;
    }
};