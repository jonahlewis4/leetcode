class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        int numCharsInSection = numRows + numRows - 2;
        int numSections = (int)std::ceil((double)s.size() / numCharsInSection); 
        int sectionWidth = numRows - 1;
        
        string res(s.size(), '.');
        int sectionNumber = 0;
        int i = 0;
        while(i < s.size()) {
            int resI = sectionNumber;
            int curRow = 0;
            int remainingSections = numSections - sectionNumber - 1; 
            for(int curRow = 0; curRow < numRows; curRow++) {
                if(i >= s.size()) {
                    return res;
                }
                res[resI] = s[i];
                resI++;
                bool dualRow = curRow != 0 && curRow != numRows - 1;
                int gap = (numRows - curRow - 1) * 2;
                if(dualRow) {
                    //add bonus character
                    if(i + gap < s.size()) {
                        res[resI] = s[i + gap];
                        resI++;
                    }
                }
                //calculate number of chars to right to skip.
                int numToSkipRight = 0;
                if(remainingSections > 1) {
                    int numPerSectionInThisRow = dualRow ? 2 : 1;
                    numToSkipRight += numPerSectionInThisRow * (remainingSections - 1); 
                }
                if(remainingSections > 0) {
                    int iInFinalSection = numCharsInSection * (numSections - 1);
                    int iInThisRowFinalSection = iInFinalSection + curRow;
                    if(iInThisRowFinalSection < s.size()){
                        numToSkipRight++;
                        if(dualRow && (iInThisRowFinalSection + gap < s.size())) {
                            numToSkipRight++;
                        }
                    }
                }
                
                //calculate number of chars left to skip
                int numPerSectionInNextRow = (curRow + 1 == numRows - 1) ? 1 : 2;
                int numToSkipLeft = numPerSectionInNextRow * sectionNumber;

                int numToSkip = numToSkipRight + numToSkipLeft;
                resI += numToSkip;
                i++;
            }
            sectionNumber++;
            i += numCharsInSection - numRows;
        }
        return res;
    }
};