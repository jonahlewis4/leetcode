class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstWordValue = numericalValue(firstWord);
        int secondWordValue = numericalValue(secondWord);
        int targetWordValue = numericalValue(targetWord);
        return firstWordValue + secondWordValue == targetWordValue;
    }

    int numericalValue(const string& s) {
        int val = 0;
        for(const char c : s) {
            val *= 10;
            val += c - 'a';
        }
        return val;
    }
};