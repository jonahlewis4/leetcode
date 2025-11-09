class Solution {
public:
    int countOperations(int num1, int num2) {
        for(int i = 0; true; ) {
            if(num1 == 0 || num2 == 0) {
                return i;
            }

            i += num1 / num2;
            num1 %= num2;

            swap(num1, num2);


        }
    }
};