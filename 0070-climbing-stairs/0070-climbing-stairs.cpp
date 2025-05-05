class Solution {

    class Memo{
        vector<int> cache;

    public:
        Memo(){

        }
        int Solution(int n) {
            cache.resize(n + 1, -1);
            return recurse(n);
        }
        int recurse(int n){
            if(n <= 0){
                return 0;
            }
            if(n == 1){
                return 1;
            }
            if(n == 2){
                return 2;
            }

            if(cache[n] != -1){
                return cache[n];
            }
            cache[n] = recurse(n - 1) + recurse(n - 2);
            return cache[n];
        }
    };

    class DP{
    public:
        int Solution(int n){
            if(n == 0){
                return 0;
            }
            if(n == 1){
                return 1;
            }
            if(n == 2){
                return 2;
            }
            int oneAgo = 2;
            int twoAgo = 1;
            int cur;
            for(int i = 3; i <= n; i++){
                cur = twoAgo + oneAgo;
                twoAgo = oneAgo;
                oneAgo = cur;
            }
            return cur;
        }

    };
public:
    int climbStairs(int n) {
        return DP().Solution(n);
    }
    

};
