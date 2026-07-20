class Solution {
    bool digitsFound = false;
    void parseSign(const string& s, int& i) {
        //advance past a sign if present
        if(i >= s.size()) {
            return;
        }
        char c = s[i];
        if(c == '-' || c == '+') {
            i++;
        }
    }
    void parseInt(const string& s, int& i) {
        while(i < s.size()) {
            char c = s[i];
            if(!isdigit(c)) {
                return;
            }
            digitsFound = true;
            i++;
        }
    }
    bool parseDecimal(const string& s, int& i) {
        if(i >= s.size()) {
            return true;
        }
        if(s[i] != '.') {
            return true;
        }
        i++;
        if(!digitsFound && i == s.size()) {
            return false;
        }
        while(i < s.size()) {
            char c = s[i];
            if(!isdigit(c)) {
                return true;
            }
            digitsFound = true;
            i++;
        }

        return true;
    }   
    bool parseExponent(const string& s, int& i) {
        if(i == s.size()) {
            return true;
        }

        if(!digitsFound) {
            return false;
        }
        char indicator = s[i];
        if(indicator != 'E' && indicator != 'e') {
            return false;
        }
        i++;

        parseSign(s, i);

        if(i == s.size()) {
            return false;
        }

        while(i < s.size()) {
            char c = s[i];
            if(!isdigit(c)) {
                return false;
            }
            i++;
        }

        return true;
    }
public:
    bool isNumber(string s) {
        int i = 0;
        parseSign(s, i);
        parseInt(s, i);
        if(!parseDecimal(s, i)){
            return false;
        }
        if(!parseExponent(s, i)){
            return false;
        }
        return i >= s.size() && digitsFound;
    }
};