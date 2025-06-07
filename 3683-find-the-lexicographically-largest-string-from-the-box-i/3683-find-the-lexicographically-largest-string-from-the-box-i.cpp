class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans = "";

        if(numFriends == 1){
            return word;
        }

        int bestLen = word.size() - numFriends + 1;

        int bestSuffixStart = bestPrefixStart(word);

        //either goes to end, or grab the bestLen;

        return word.substr(bestSuffixStart, min(bestLen, int(word.size()) - bestSuffixStart));
       
    }

    int bestPrefixStart(const string& word) const {
        int l = 0;
        int r = 1;
        int k = 0;
        while(r + k < word.size()){
            if(word[l + k] == word[r + k]){
                k++;
            } else if (word[l + k] < word[r + k]){
                l = max(l + k + 1, r);
                r = l + 1;
                k = 0;
            } else {
                r++;
                k = 0;
            }
        }
        return l;
    }
};