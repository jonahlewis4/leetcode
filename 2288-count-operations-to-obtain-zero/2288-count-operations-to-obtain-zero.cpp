class Solution {
public:
    int countOperations(int num1, int num2) {
        for(int i = 0; true; i++) {
            if(num1 < num2) {
                swap(num1, num2);
            }

            if(num1 == 0 || num2 == 0) {
                return i;
            }

            num1 -= num2;

        }
    }
};