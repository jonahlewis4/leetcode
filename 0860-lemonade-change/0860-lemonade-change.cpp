class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twenties = 0;

        for(const int  bill : bills) {
            if(bill == 5){
                fives++;
                continue;
            }

            if(bill == 10) {
                if(fives == 0) {
                    return false;
                }

                fives--;
                tens++;
                continue;
            }

            if(bill == 20) {
                if(tens >= 1 && fives >= 1) {
                    fives--;
                    tens--;
                    continue;
                } else if (fives >= 3) {
                    fives -= 3;
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};