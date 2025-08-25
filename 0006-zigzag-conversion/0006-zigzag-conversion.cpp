class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }

        string res(s.size(), '.');
        int numCharsInSection = numRows * 2 - 2;

        int i = 0;
        for(int r = 0; r < numRows; r++) {
            int position = r;
            while(true){
                if(position >= s.size()) {
                    break;
                }
                res[i] = s[position];
                i++;
                int nextSection = position + numCharsInSection;

                if(r != 0 && r != numRows - 1) {
                    int gap = numCharsInSection - r * 2;
                    position += gap;
                    if(position >= s.size()) {
                        break;
                    }
                    res[i] = s[position];
                    i++;
                }
                position = nextSection;
            }
        
        }
        return res;
    }
};