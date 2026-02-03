class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0) {
            return 0;
        }
        int segs = 0;
        bool lastWasSpace = true;
        for(const char c : s) {
            if(c == ' ' && !lastWasSpace) {
                segs++;
            }

            if(c == ' ') {
                lastWasSpace = true;
            } else {
                lastWasSpace = false;
            }
        }

        if(s.back() != ' ') {
            segs++;
        }

        return segs;
    }
};