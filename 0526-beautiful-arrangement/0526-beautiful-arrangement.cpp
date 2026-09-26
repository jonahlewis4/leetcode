class Solution {
private: 
    int n;
    int r(int i, int mask) {
        if(i > n) {
            return 1;
        }
        
        if(cache[mask] != -1) {
            return cache[mask];
        }
        int total = 0;
        for(int j = 0; j < n; j++) {
            if((mask&(1<<j))!=0) {
                continue;
            }

            if(!(i % (j+1) == 0 || (j+1)%i==0)){
                continue;
            }

            int newMask = (mask | (1<<j));
            total += r(i+1, newMask);
        }
        cache[mask] = total;
        return total;
    }
public:
    vector<int> cache;
    int countArrangement(int n) {
        cache.resize((1<<n)+1,-1);
        this->n = n;
        return r(1, 0);
    }
};