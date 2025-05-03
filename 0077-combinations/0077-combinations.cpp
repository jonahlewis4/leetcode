class Solution {
vector<vector<int>> res;
vector<int> cur;
int n;
int k;
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        dfs(1);
        return res;  
    }
    void dfs(int newDigit) {
        
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        
        int remaining = n - newDigit + 1;
        if(cur.size() + remaining < k){
            return;
        }

        //find all combinations with this digit in it;

        for(int secondDigit = newDigit; secondDigit <= n; secondDigit++){
            cur.push_back(secondDigit);
            dfs(secondDigit + 1);
            cur.pop_back();
        }


    }
};