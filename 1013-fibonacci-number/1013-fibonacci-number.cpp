class Solution {
private:

public:
    int fib(int n) {
        
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        int twoAgo = 0;
        int oneAgo = 1;
        int cur;
        for(int i = 2; i <= n; i++){
            cur = twoAgo+oneAgo;
            twoAgo = oneAgo;
            oneAgo = cur;
        }
        return cur;

    }
};

