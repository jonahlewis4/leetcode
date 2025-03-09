class Solution {
private:
public:
    vector<vector<string>> partition(const string& s) {
        vector<vector<string>> res;
        vector<vector<bool>> pals = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        vector<string> cur = {};
        calc(0, res, pals, cur, s);
        return res;
    }
    void calc(int i, vector<vector<string>>& res, vector<vector<bool>>& pals, vector<string>& cur, const string& s){
        if(i >= s.size()){
            res.push_back(cur);
            return;
        }
        string newPal = "";
        for(int j = i; j < s.size(); j++){
            newPal.push_back(s[j]);
            bool singleLetter = newPal.size() == 1;
            bool edgesMatch = newPal[0] == newPal[newPal.size() - 1];
            bool doubleLetter = newPal.size() == 2;
            if(singleLetter || (edgesMatch && (doubleLetter || (pals[i + 1][j - 1]) ) ) ){
                cur.push_back(newPal);
                pals[i][j] = true;
                calc(j + 1, res, pals, cur, s);
                cur.pop_back();
            }
        }
    }
};