class Solution {
private:
    static char tolower(const char c) {
        if(c >= 'A' && c <='Z') {
            return c - 'A' + 'a';
        }
        return c;

    }
public:
    string toLowerCase(string s) {
        for(char& c : s) {
            c = tolower(c);
        }
        return s;
    }
};