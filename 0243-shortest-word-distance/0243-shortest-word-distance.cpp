class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int lastWord = -1;
        int shortestDistance = INT_MAX;
        for(int i = 0; i < wordsDict.size(); i++) {
            string cur = wordsDict[i];
            if(cur == word1 || cur == word2) {
                if(lastWord == -1){
                    lastWord = i;
                } else if (cur == wordsDict[lastWord]) {
                    lastWord = i;
                } else {
                    shortestDistance = min(i - lastWord, shortestDistance);
                    lastWord = i;
                }
            }
        }
        return shortestDistance;
    }
};