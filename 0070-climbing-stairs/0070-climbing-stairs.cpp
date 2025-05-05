class Solution {
    vector<int> cache;
public:
    int climbStairs(int n) {
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
