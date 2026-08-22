class Solution {
    public boolean checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int n2 = n;
        while(n > 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n/=10;
        }
       
        boolean answer = (n2 % (sum + product)) == 0;
        return answer;
    }
}