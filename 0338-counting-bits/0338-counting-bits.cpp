class Solution {
public:
    vector<int> countBits(int n) {
        
        if(n == 0){
            return {0};
        }

        vector<int> res(n + 1);
        res[0] = 0;
        res[1] = 1;

        int offsetCounter = 0;
        int offset = 2;

        for(int i = 2; i <= n; i++){
            res[i] = 1 + res[i - offset];
            offsetCounter++;
            if(offsetCounter >= offset){
                offset *= 2;
                offsetCounter = 0;
            }
        }
        return res;
    }
    
};