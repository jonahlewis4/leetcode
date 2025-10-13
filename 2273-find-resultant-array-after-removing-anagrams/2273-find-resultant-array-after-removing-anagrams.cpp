class Solution {
    bool isAna(string a, string b) {
        if(a.size() != b.size()){
            return false;
        }

        unordered_map<char, int> ac;
        
        for(const char c : a) {
            ac[c]++;
        }

        unordered_map<char, int> bc;
        for(const char c : b){
            bc[c]++;
            if(bc[c] > ac[c]) {
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