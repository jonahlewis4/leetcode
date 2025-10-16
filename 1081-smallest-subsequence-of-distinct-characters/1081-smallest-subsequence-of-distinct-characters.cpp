class Solution {
public:
    string smallestSubsequence(const string& s) {
        vector<int> last(26);
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            last[c - 'a'] = i;
        }
        string res = "";
        vector<bool> seen(26, false);
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(seen[c - 'a']){
                continue;
            }
            while(!res.empty() && res.back() >= c && last[res.back() - 'a'] > i){
                seen[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            seen[res.back() - 'a'] = true;
           
        }
        return res;
    }
};