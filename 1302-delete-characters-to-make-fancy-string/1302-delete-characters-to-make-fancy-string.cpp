class Solution {
public:
    string makeFancyString(string s) {
        int streak = 0;
        char prev = '\0';
        int sum = 0;
        string sBuilder = "";
        for(const auto & c : s) {
            if(c == prev) {
                streak++;
            } else {
                streak = 1;
            }
            if(streak < 3) {
                sBuilder += c;
            }
            prev = c;
        }
        return sBuilder;
    }
};