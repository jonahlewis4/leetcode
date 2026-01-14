class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }

        for(int i = 0; i < s.size(); i++) {
            if(checkEqWithRotateOnS(i, s, goal)){
                return true;
            }
        }

        return false;
    }

    bool checkEqWithRotateOnS(int shift, const string& s, const string& goal) {
        for(int i = 0; i < s.size(); i++) {
            int sI = (i + shift) % s.size();
            if(s[sI] != goal[i]) {
                return false;
            }
        }

        return true;
    } 
};