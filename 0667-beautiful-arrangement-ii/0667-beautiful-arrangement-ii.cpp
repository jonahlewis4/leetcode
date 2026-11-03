class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        res.front() = 1;
        int gap = n-1;
        for(int i = 1; i < res.size(); i++){
            if(k > 1){
                int nextVal = res[i-1] + gap;
                res[i] = nextVal;
                if(gap < 0){
                    gap = -gap - 1;
                } else {
                    gap = -gap + 1;
                }
                k--;
            } else {
                int gapAdjustment = gap < 0 ? -1 : 1;
                res[i] = res[i-1] + gapAdjustment;
            }
        }

        return res;
    }
};