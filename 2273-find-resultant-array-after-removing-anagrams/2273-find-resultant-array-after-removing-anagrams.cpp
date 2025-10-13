class Solution {

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
    
        res.push_back(words.front());
        for(int i = 1; i < words.size(); i++){
            string second = res.back();
            string third = words[i];
            sort(second.begin(), second.end());
            sort(third.begin(), third.end());
            if(second == third) {
            } else {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};