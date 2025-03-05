class Solution {
private:
vector<vector<int>> pals;
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;

        pals = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        vector<string> cur;
        calc(cur, res, s, 0, 0);  
        return res;  
    }

    void calc(vector<string>& cur, vector<vector<string>>& res, const string& s, int l, int r){
        while(r < s.size()){
            if (isPal(s, l, r)){
                cur.push_back(s.substr(l, r - l + 1));
                if(r == s.size() - 1){
                    res.push_back(cur);
                } else {
                    calc(cur, res, s, r +1, r + 1);
                }
                cur.pop_back();
            }
            r++;
        }
        
    }



    bool isPal(const string&s, int l, int r){
        int ogL = l;
        int ogR = r;
        if(pals[l][r] != -1){
            return pals[l][r];
        }
     
        while(l <= r){
            if(s[l] != s[r]){
                pals[ogL][ogR] = false;
                return false;
            }
            l++;
            r--;
        }
        pals[ogL][ogR] = true;
        return true;
    }

};