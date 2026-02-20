class Solution {
public:
    string sortSentence(string s) {
        vector<string> strs(9, "");
        string cur = "";
        int num = 0;
        for(const char c : s) {
            if(c == ' ') {
                // cout<<cur<<endl;
                // cout<<num<<endl;
                strs[num - 1] = cur;
                num = 0;
                cur = "";
            } else if (isalpha(c)) {
                cur += c;
            } else if (isdigit(c)) {
                num *= 10;
                num += c - '0';
            }
        }

        strs[num - 1] = cur;


        string res;
        for(int i = 0; i < strs.size(); i++) {
            const string& s = strs[i];
            if(s == "") {
                break;
            }

            res += s + " ";
        }

        res.pop_back();

        return res;
    }
};