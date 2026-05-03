class Solution {
private:
    static int weight(const string& s, vector<int>& weights) {
        int res = 0;
        for(const char c : s) {
            int i = c - 'a';
            res += weights[i];
        }
        return res;
    }
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for(const string& word : words) {
            int w = weight(word, weights);
            int modW = w%26;
            res.push_back('z' - modW);
        }

        return res;
    }
};