class Solution {
private:
    vector<vector<string>> res;
    string s;
    vector<string> cur;
    vector<vector<bool>> pals;
public:
    vector<vector<string>> partition(const string& s) {
        res = {};
        this->s = s;
        pals = vector<vector<bool>>(this->s.size(), vector<bool>(this->s.size(), false));
        cur = {};
        calc(0);
        return res;
    }
    void calc(int i){
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
                calc(j + 1);
                cur.pop_back();
            }
        }
    }
};