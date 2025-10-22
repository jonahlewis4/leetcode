class Solution {
public:
    int integerReplacement(int n) {
        
        if(n == INT_MAX) {
            return 32;
        }

        for(int i = 0; true; i++) {
            if(n == 1) {
                return i;
            }

            if(n == 3){
                return i + 2;
            }

            if(n % 2 == 0) {
                n/=2;
            } else {
                int andResult = (n & 0b11);

                if(andResult == 0b11) {
                    n++;
                } else {
                    n--;
                }
            }

        }
    }
};