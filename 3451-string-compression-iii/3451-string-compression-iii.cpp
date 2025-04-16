class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int prefixLength = 0;
        char prefixChar = word[0];
        for(int i = 0; i < word.size(); i++){
            if(word[i] != prefixChar){
                compress(comp, prefixLength, prefixChar);
                prefixChar = word[i];
                prefixLength = 0;
            }
            prefixLength++;
        }
        compress(comp, prefixLength, prefixChar);
        return comp;
    }

    inline void compress(string &comp, int prefixLength, char prefixChar) const {
        if(prefixLength == 0){
            return;
        }
        while(prefixLength > 9){
            comp.push_back('9');
            comp.push_back(prefixChar);
            prefixLength -= 9;
        }
        comp.push_back(prefixLength + '0');
        comp.push_back(prefixChar);
        prefixLength = 0;
    }
};