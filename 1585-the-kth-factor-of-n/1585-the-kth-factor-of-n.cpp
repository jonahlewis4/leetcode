class Solution {
public:
    int kthFactor(int n, int k) {
        int lCount = 0;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                lCount++;
                if(lCount == k){
                    return i;
                }
            }
        }

        int totalFactors = lCount * 2;
        if (sqrt(n) - floor(sqrt(n)) == 0){
            totalFactors -= 1;
        }

        for(int i = n; i >= sqrt(n); i--){
            if(n % i == 0){
                if(totalFactors == k){
                    return i;
                }
                totalFactors--;
            }
        }
        
        return -1;
    }
};