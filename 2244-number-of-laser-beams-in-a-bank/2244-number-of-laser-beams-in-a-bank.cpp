class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int previousBeamCount = 0;
        int total = 0;
        for(const string& row : bank){
            int curBeamCount = 0;
            for(const char c : row) {
                if(c == '1'){
                    curBeamCount++;
                }
            }

            if(curBeamCount != 0){
                total += previousBeamCount * curBeamCount;
                previousBeamCount = curBeamCount;
            }
    
        }

        return total;
    
    }
};