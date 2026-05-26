class Solution {
    static int numWords(const string& sentence) {
        int spacesCount = std::count(sentence.begin(), sentence.end(), ' ');
        return spacesCount + 1;
    }
public:
    int mostWordsFound(vector<string>& sentences) {
        int best = 0;
        for(const string& sentence : sentences) {
            int words = numWords(sentence);
            best = std::max(best, words);
        }
        return best;
    }
};