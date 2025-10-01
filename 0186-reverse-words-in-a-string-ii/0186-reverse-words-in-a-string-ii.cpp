class Solution {
public:
    void reverseWords(vector<char>& s) {
        vector<char>::iterator begin = s.begin();
        for(auto itr = s.begin(); itr != s.end(); itr++){
            if(*itr == ' '){
                reverse(begin, itr);
                begin = itr + 1;
            }
        }
        reverse(begin, s.end());
        reverse(s.begin(), s.end());
    }
};