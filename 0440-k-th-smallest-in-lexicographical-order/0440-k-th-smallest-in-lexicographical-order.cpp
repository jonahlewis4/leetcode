class Solution {
private: 
    int k;
    int n;
    int i;
public:
    int findKthNumber(int n, int k) {
        this->k = k;
        this->n = n;
        this->i = 1;
        
        int res = 1;
        while(i < k){
            int dist = numElem(res, res + 1);
            if(i + dist <= k){
                res++;
                i += dist;
            } else {
                res *= 10;
                i++;
            }
        }
        return res;
        
    }

    int numElem(long l, long r) const{
        int sum = 0;
        while(l <= n){
            sum += min(r, (long)n + 1) - l;
            l *= 10;
            r *= 10;
        }
        return sum;
    }

    
};