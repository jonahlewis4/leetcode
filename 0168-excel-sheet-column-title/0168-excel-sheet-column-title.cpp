class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<int> digitsInAscendingSignificance;

        while(columnNumber > 0){
            columnNumber--;
            int rem = columnNumber % 26;
            int newColumnNumber = (columnNumber) / 26;
            digitsInAscendingSignificance.push_back(rem);
            columnNumber = newColumnNumber;
        }

        string res = "";
        for(int i = digitsInAscendingSignificance.size() - 1; i >= 0; i--){
            int numDigit = digitsInAscendingSignificance[i];
            char charDigit = 'A' + numDigit;
            if(charDigit < 'A'){
                charDigit = 'Z';
            }
            res += charDigit;
        }

        return res;
    }
};