class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string ogA = a;
        int i = 1;
        while(a.size() < b.size()){
            a += ogA;
            i++;
        }

        if(a.find(b) != string::npos) {
            return i;
        }

        a += ogA;
        if(a.find(b) != string::npos) {
            return i + 1;
        }

        return -1;
    }
};