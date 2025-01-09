class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> tCount;
        for(const char c : t){
            tCount[c]++;
        }

        std::unordered_map<char, int> sCount;
        

        int l = 0;
        int r = 0;
        int optimalL = l;
        int minLen = INT_MAX;
        int matches = 0;
        int matchGoal = tCount.size();
        while(r < s.size()){
            //move right until all match.
            while(r < s.size() && matches < matchGoal){
                sCount[s[r]]++;
                if(sCount[s[r]] == tCount[s[r]] && tCount[s[r]] != 0){
                    matches++;
                }
                r++;
            }
            
           //move left until no longer match, record length. 
            while(l < s.size() && matches == matchGoal){
                sCount[s[l]]--;
                if(sCount[s[l]] == tCount[s[l]] - 1){
                    matches--;
                }

                int length = r - l;
                if(length < minLen){
                    minLen = length;
                    optimalL = l;
                }

                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(optimalL, minLen);
      

    }
};