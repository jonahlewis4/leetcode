class Solution {
public:
    bool repeatedSubstringPattern(const string& s) {
        string build = "";
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            build.push_back(c);
            
            int start = 0;
            while(true) {
                int newStart = s.find(build, start+build.size());
                if(newStart == string::npos || newStart - start > build.size()) {
                    break;
                }
                if(newStart + build.size() == s.size()) {
                    return true;
                }

                start = newStart;

            }
        }

        return false;
    }
};