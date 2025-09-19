class Solution {
    unordered_map<int, int> cache;
public:
    int numTrees(int n) {
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return 1;
        }

        if(cache.find(n) != cache.end()){
            return cache[n];
        }

        n--;
        int total = 0;
        for(int l = 0; l <= n; l++) {
            int r = n - l;
            int lComb = numTrees(l);
            int rComb = numTrees(r);
            total += lComb * rComb;
        }                          
        cache[n + 1] = total;
        return total;  
    }
};