class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string temp = "";
            for(int i = 1; i < s.size(); i++) {
                char prev = s[i - 1];
                char cur = s[i];

                char next = (prev - '0' + cur - '0')% 10 + '0';
                temp += next;
            }

            s = temp;
        }

        return s.front() == s.back();
    }
};