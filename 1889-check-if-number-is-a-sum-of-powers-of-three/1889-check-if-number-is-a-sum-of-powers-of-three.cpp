class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        return check(n, 1);
        
    }

    bool check(int n, int threePow){
        if(n == 0){
            return true;
        }
        if(n < 0 || threePow > n){
            return false;
        }
        

        bool use = check(n - threePow, threePow * 3);
        bool dontUse = check(n, threePow * 3);
        return use || dontUse;
    }
    
    
};