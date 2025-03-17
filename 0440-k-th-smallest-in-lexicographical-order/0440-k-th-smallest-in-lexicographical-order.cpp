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
        for(int j = 1; j <= 9; j++){
            if(i == k){
                return j;
            }
            int numElements = numElem(j, j + 1);
            
            if(numElements + i == k){
                return j + 1;
            } else if(numElements + i > k){
                i++;
                return lexi(j);
            } else {
                i += numElements;
                continue;
            }
        }
        return -1;
        
    }

    int lexi(const int curNum){
        if(i == k){
            return curNum * 10;
        }
        int curNumTen = curNum * 10;
        for(int j = 0; j <= 9; j++){
            int numElements = numElem(curNumTen + j, curNumTen + j + 1);
            if(i + numElements == k){
                return curNum * 10 + j + 1;
            } else if(i + numElements > k){
                i++;
                return lexi(curNumTen + j);
            } else {
                i += numElements;
                continue;
            }
        }
        return -1;
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