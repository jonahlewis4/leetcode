class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> smallCount;

        for(const char c : t){
            smallCount[c]++;
        }


        std::unordered_map<char, int> bigCount;
        int matchGoal = smallCount.size();
        int matches = 0;
        int l = 0;
        int r = 0;
        int sLen = s.size();
        int minWindow = INT_MAX;
        int minL = -1;
        while(r < sLen){
            bigCount[s[r]]++;
            if(bigCount[s[r]] == smallCount[s[r]]){
                matches++;
            }

            

            while(matches == matchGoal){
                if(matches == matchGoal){
                    int len = r - l + 1;
                    if(len < minWindow){
                        minWindow = len;
                        minL = l;
                    }
                }
                bigCount[s[l]]--;
                if(bigCount[s[l]] ==  smallCount[s[l]] - 1){
                    matches--;

                }
                l++;
            }
            r++;
        }
      
        if(minWindow == INT_MAX){
            return "";
        }
        return s.substr(minL, minWindow);
    }
};