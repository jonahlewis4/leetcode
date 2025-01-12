class Solution {
public:
    string reverseWords(string s) {
        vector<string> splitStrings = split(s, " ");
        reverse(splitStrings.begin(), splitStrings.end());
        string res = "";
        for(const string & str : splitStrings){
            if(str != ""){
                res += str + " ";
            }
        }
        res.pop_back();
        return res;
    }
    std::vector<string> split(const string &s, const string &delim){
        std::vector<string> tokens;
        int start = 0;
        int end = s.find(delim);

        while(end < s.size()){
            tokens.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(delim, start);
        }

        tokens.push_back(s.substr(start, end - start));

        return tokens;
    }
};