class Solution {
    class Recursive{
    public:
        bool wordBreak(string s, vector<string> & wordDict) {
            unordered_set<string> set;
            for(auto & s : wordDict){
                set.insert(s);
            }
            string builder = "";
            return calc(s, set, 0, builder);
        }
        bool calc(const string &s, unordered_set<string> &set, int i, string &built) const{
            if(i == s.size() && set.find(built) != set.end()){
                return true;
            }

            if(i >= s.size()){
                return false;
            }

            //try with extended word
            built.push_back(s[i]);
            bool extend = calc(s, set, i + 1, built);
            if(extend){
                return true;
            }
            built.pop_back();
            
            //if this is a word try with empty.
            if(set.find(built) != set.end()){
                string newBuilt = "";
                newBuilt.push_back(s[i]);
                bool split = calc(s, set, i + 1, newBuilt); 
                if(split){
                    return true;
                }       
            }

            return false;

        }
    };

    class Memo{
    private:
        vector<int> stretch;
    public:
        bool wordBreak(string s, vector<string> & wordDict) {
            unordered_set<string> set;
            stretch.resize(s.size(), -1);
            for(auto & s : wordDict){
                set.insert(s);
            }
            string builder = "";
            return calc(s, set, 0, builder);
        }
        bool calc(const string &s, unordered_set<string> &set, int i, string &built) {
            if(i == s.size() && set.find(built) != set.end()){
                return true;
            }

            if(i >= s.size()){
                return false;
            }
            int stretchStart = i - built.size();
            if(stretch[stretchStart] != -1){
                return stretch[stretchStart];
            }

            //try with extended word
            
            built.push_back(s[i]);
            bool extend = calc(s, set, i + 1, built);
            if(extend){
                stretch[stretchStart] = true;
                return true;
            }
            built.pop_back();
            
            //if this is a word try with empty.
            if(set.find(built) != set.end()){
                string newBuilt = "";
                newBuilt.push_back(s[i]);
                bool split = calc(s, set, i + 1, newBuilt); 
                if(split){
                    stretch[stretchStart] = true;
                    return true;
                }

                

            }
            stretch[stretchStart] = false;
            return false;

        }
    };
    class DP{
    public:

        bool wordBreak(const string &s, vector<string> &wordDict){
            unordered_set<string> set;
            for(auto & s : wordDict){
                reverse(s.begin(), s.end());
                set.insert(s);
            }
            vector<bool> dp(s.size(), false);
            dp.back() = ( set.find(s.substr(s.size() - 1, 1)) != set.end() );

            string cur = {s.back()};
            for(int i = dp.size() - 2; i >= 0; i--){
                cur += s[i];
                //if current build in dict dp[i] = true;
                if(set.find(cur) != set.end()){
                    dp[i] = true;
                    continue;
                }

                //if it isn't a word, check if  it can be split into two differnt words from any of the true ones to the right.

                string curFromSplit = cur;
                string split = "";
                for(int r = dp.size() - 1; r > i; r--){
                    split += s[r];
                    curFromSplit.erase(curFromSplit.begin());
                    if(!dp[r]){
                        continue;
                    }


                    if(set.find(curFromSplit) != set.end()){
                        dp[i] = true;
                        continue;
                    }
                }

            }


            return dp[0];
        }

        class OptimalDP{
        public:
            bool wordBreak(string s, vector<string> &wordDict) const {
                unordered_set<string> set(wordDict.begin(), wordDict.end());

                vector<bool> dp(s.size() + 1, false);

                //loop through all possible endings of the string. 
                    //check all possibel beginnings for that string. 
                    //if the area before that start is set to true
                    //and if the substring from the start to the end is in the dict
                    //set the end to 


                return dp[s.size()];
            }
        };
    };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return DP().wordBreak(s, wordDict);
    }    
};