class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> cand;
        dfs(0, 0, 0, res, cand, n);
        return res;
    }
    void dfs(int lCount, int rCount, int stackCount, vector<string> &res, vector<char> &cand, int pairs){
        if(lCount == pairs && rCount == pairs){
            string ans = "";
            for(const auto & c : cand){
                ans += c;
            }
            res.push_back(ans);
            return;
        }
        if(lCount + 1 <= pairs){
            cand.push_back('(');
            dfs(lCount + 1, rCount, stackCount + 1, res, cand, pairs);
            cand.pop_back();
        }
        if(rCount + 1 <= pairs && stackCount > 0){
            cand.push_back(')');
            dfs(lCount, rCount + 1, stackCount - 1, res, cand, pairs);
            cand.pop_back();
        }



    }
};