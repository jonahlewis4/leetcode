class Solution {
private:
    vector<vector<string>> res;
    vector<string> cur;
    vector<vector<bool>> pals;
    string s;
public:
    vector<vector<string>> partition(string s) {
        res = {};
        cur = {};
        pals = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        this->s = s;
        calc(0);
        return res;
    }

    void calc(int i){
        //check if exceeded
        if(i >= s.size()){
            res.push_back(cur);
            return;
        }
        string candidate = "";
        for(int j = i; j < s.size(); j++){
            candidate.push_back(s[j]);
            if(s[i] == s[j]){
                if(j - i == 0 || j - i == 1 || pals[i + 1][j - 1]){
                    pals[i][j] = true;
                    cur.push_back(candidate);
                    calc(j + 1);
                    cur.pop_back();
                }
            }
        }
    }
};