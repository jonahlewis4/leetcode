class Solution {
public:
    bool checkPowersOfThree(int n) {
        int subject = 3; 
        while(n > 0){
            if (n % 3 == 2) {
                return false;
            }

            n /= 3;
        }

        return true;
    }

    
    
    
};