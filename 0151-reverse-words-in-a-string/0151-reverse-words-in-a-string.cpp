class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        int i = 0;
        while(r < s.size()){
            while(l < s.size() && s[l] == ' '){
                l++;
            }
            r = l;
            while(r < s.size() && s[r] != ' '){
                s[i] = s[r];
                i++;
                r++;
            }

            if(i < s.size()) {
                s[i] = ' ';
            }
            reverse(s.begin() + i - (r - l), s.begin() + i);
            i++;


            l = r + 1;
        }
        while(s.size() > i || (!s.empty() && s.back() == ' ')){
            s.pop_back();
        }
        reverse(s.begin(), s.end());

        return s;
    }
    

    
};