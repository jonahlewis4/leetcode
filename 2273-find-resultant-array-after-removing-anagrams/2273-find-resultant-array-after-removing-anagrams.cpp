class Solution {
    bool isAna(string a, string b) {
        if(a.size() != b.size()){
            return false;
        }

        vector<char> ac(26, 0);
        
        for(const char c : a) {
            ac[c - 'a']++;
        }

        vector<char> bc(26, 0);
        for(const char c : b){
            bc[c - 'a']++;
            if(bc[c - 'a'] > ac[c - 'a']) {
                return false;
            }
        }

        return true;

        
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words.front());
        for(int i = 1; i < words.size(); i++){
            string& second = res.back();
            string& third = words[i];
            if(isAna(second, third)) {
            } else {
                res.push_back(third);
            }
        }
        return res;
    }
};