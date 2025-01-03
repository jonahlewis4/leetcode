class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        bool swapped = false;
        if(word1.size() < word2.size()){
            std::swap(word1, word2);
            swapped = true;
        }
        std::string res = "";
        int i = 0;
        while(i < word2.size()){
            if(swapped){
                res.push_back(word2[i]);
                res.push_back(word1[i]);
            } else {
                res.push_back(word1[i]);
                res.push_back(word2[i]);
            }
            i++;
        }

        while(i < word1.size()){
            res.push_back(word1[i]);
            i++;
        }
        return res;
    }
};