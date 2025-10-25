class Solution {
    int summate(int n) {
        return ((n) * (n + 1)) / 2;
    }
    int tab(int dayIndex, int n) {
        int wholeRotations = n/7;
        int dayValueStart = dayIndex + 1;
        int finalNum = dayValueStart + wholeRotations - 1;
        if(n % 7 > dayIndex){
            finalNum++;
        }

        return summate(finalNum) - summate(dayIndex);

    }
public:
    int totalMoney(int n) {
        int total = 0;
        
        for(int i = 0; i <= 6; i++) {
            total += tab(i, n);
        }

        return total;
    }
};