class Solution {
public:
    string reverseWords(string s) {
        auto start = s.begin();
        for(auto itr = s.begin(); itr != s.end(); itr++) {
            char c = *itr;
            if(c == ' ') {
                reverse(start, itr);
                start = itr + 1;
                itr++;
            }
        }
        reverse(start, s.end());
        return s;
    }
};