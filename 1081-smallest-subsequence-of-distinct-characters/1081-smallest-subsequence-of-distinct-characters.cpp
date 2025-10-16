class Solution {
public:
    string smallestSubsequence(const string& s) {
        unordered_map<char, int> last;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            last[c] = i;
        }
        string res = "";
        unordered_set<char> seen;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(seen.contains(c)){
                continue;
            }
            while(!res.empty() && res.back() >= c && last[res.back()] > i){
                seen.erase(res.back());
                res.pop_back();
            }
            res.push_back(c);
            seen.insert(res.back());
           
        }
        return res;
    }
};