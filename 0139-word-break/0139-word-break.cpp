class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> canStart(s.size() + 1, false);
        canStart[0] = true;

        for(int i = 0; i <= s.size(); i++){
            for(const auto & word : wordDict){
                int sz = word.size();
                int start = i - word.size();
                if(start < 0){
                    continue;
                }
                if(canStart[start]){
                    string preceeding = s.substr(start, i - start);
                    if(preceeding == word){
                        canStart[i] = true;
                    }
                }
            }
        }

        return canStart.back();
    }
};