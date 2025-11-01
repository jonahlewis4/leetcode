class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int last1 = -1;
        int last2 = -1;


        int res = INT_MAX;

        bool sameWord = word1 == word2;

        for(int i = 0; i < wordsDict.size(); i++){
            const string& s = wordsDict[i];
            if(s != word1 && s != word2){
                continue;
            }

            if(s == word1){
                last1 = i;

                if(last2 != -1) {
                    int dist = i - last2;
                    res = min(res, dist);
                }
            }

            if(s == word2) {
                last2 = i;
                if(last1 != -1) {
                    int dist = i - last1;
                    if(!sameWord){
                        res = min(res, dist);
                    }
                }
            }
        }

        return res;
    }
};