class Solution {
private:

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<array<int, 26>> targetFreq(words2.size());
        for(int i = 0; i < words2.size(); i++){
            for(int j = 0; j < words2[i].size(); j++){
                targetFreq[i][words2[i][j] -'a']++;
            }
        }
        array<int, 26> minRequired;
        minRequired.fill(0);
        for(const auto & arr : targetFreq){
            for(int i = 0; i < arr.size(); i++){
                minRequired[i] = max(minRequired[i], arr[i]);
            }
        }

        vector<array<int, 26>> freq(words1.size());
        int i = 0;
        for(const string & word : words1){
            for(const char c : word){
                freq[i][c - 'a']++;
            }
            i++;
        }
        
        vector<string> res;
        for(int i = 0; i < freq.size(); i++){
            bool add = true;
            for(int j = 0; j < 26; j++){
                if(freq[i][j] < minRequired[j]){
                    add = false;
                    break;
                }
            }
            if(add){
                res.push_back(words1[i]);
            }
        }
        return res;

    }
};