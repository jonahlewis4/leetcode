class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            int c = s[i];
            
            //if part of 2 digit number, handle that case
            if(i + 2 < s.size() && s[i + 2] == '#'){
                int c2 = s[i + 1];
                int num = (c - '0') * 10 + c2 - '0';
                char letter = num + 'a' - 1;
                res += letter;
                i += 2;
            } else {
                char letter = c - '0' + 'a' - 1;
                res += letter;
            }
        }

        return res;
    }
};