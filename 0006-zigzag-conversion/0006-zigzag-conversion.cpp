class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string res;
        int n = s.size(); 
        int charsInSection = 2 * numRows - 2;

        for(int r = 0; r < numRows; r++){
            int i = r;
            while(i < n){
                res += s[i];

                if(r != 0 && r != numRows - 1){
                    //grab next one
                    int followIdx = i + (charsInSection - 2 * r);
                    if(followIdx < n){
                        res += s[followIdx];

                    }
                }
                i += charsInSection;
            }
        }
        return res;
    }
};