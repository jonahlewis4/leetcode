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
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return Memo().wordBreak(s, wordDict);
    }    
};