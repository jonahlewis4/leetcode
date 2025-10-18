class Solution {
public:
    string licenseKeyFormatting(const string& s, int k) {
        int charCount = 0;
        for(const char c : s) {
            if(isalnum(c)){
                charCount++;
            }
        }
        
        int numInFirstString = charCount % k;
        if(numInFirstString == 0){
            numInFirstString = k;
        }
        string res = "";
        int stringLengthLimit = numInFirstString;
        int curStringLength = 0;
        for(const char c : s){
            if(!isalnum(c)){
                continue;
            }

            res += toupper(c);
            curStringLength++;
            if(curStringLength == stringLengthLimit){
                curStringLength = 0;
                stringLengthLimit = k;
                res += '-';
            }
        }
        if(!res.empty()){res.pop_back();}
        return res;
    }
};