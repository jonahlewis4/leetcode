class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> encountered;
        while(true){
            int squareSum = _squareSum(n);
            if(squareSum == 1){
                return true;
            } else if(encountered.find(squareSum) != encountered.end()){
                return false;
            } else {
                encountered.insert(squareSum);
            }
            n = squareSum;
        }
    }
    int _squareSum(int n){
        int sum = 0;
        while(n > 0){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};