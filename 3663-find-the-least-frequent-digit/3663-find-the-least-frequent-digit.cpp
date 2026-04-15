class Solution {
public:
    int getLeastFrequentDigit(int n) {
        array<int, 10> digits;
        while(n > 0) {
            digits[n % 10]++;
            n/=10;
        }


        int smallest = -1;
        for(int i = 0; i < 10; i++) {
            if(digits[i] == 0) {
                continue;
            }
            if(smallest == -1 || digits[i] < digits[smallest]){
                smallest = i;
            }
        }

        return smallest;
    }
};