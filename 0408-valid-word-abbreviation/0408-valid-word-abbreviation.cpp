class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        while(i < abbr.size()){
            char c = abbr[i];
            if(isalpha(c) && abbr[i] != word[j]){
                return false;
            } else if(c == '0'){
                return false;
            } else if(isdigit(c)){
                int skip = 0;
                while(isdigit(abbr[i]) && i < abbr.size()){
                    skip *= 10;
                    skip += abbr[i] - '0';
                    i++;
                }
                i--;
                j += skip - 1;   
            }
            j++;
            i++;
        }
        return j == word.size();
    }
};