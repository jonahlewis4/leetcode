class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string&b){
            if(a.size() > b.size()){
                return true;
            }
            if(a.size() < b.size()) {
                return false;
            }
            return a < b;
        });
        for(const string& dict : dictionary) {
            int l = 0;
            int r = 0;
            while(l < s.size()) {
                if(s[l] == dict[r]){
                    r++;
                }

                if(r >= dict.size()) {
                    return dict;
                }
                l++;
            }
        }
        return "";
    }
};