class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    int n;
    int k;
    int curSum = 0;
    int i = 1;
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n;
        this->k = k;
        combinate();
        return res;
    }

    void combinate() {

        if(curSum > n){
            return;
        }

        if(curSum == n && cur.size() == k){
            res.push_back(cur);
            return;
        }

        if(cur.size() == k) {
            return;
        }

        for(int j = i; j <= 9; j++){
            cur.push_back(j);
            curSum += j;
            int oldI = i;
            i = j + 1;
            combinate();
            cur.pop_back();
            curSum -= j;
            i = oldI;
        }
    }
};