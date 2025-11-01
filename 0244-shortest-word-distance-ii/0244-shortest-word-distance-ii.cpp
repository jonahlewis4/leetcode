class WordDistance {
    unordered_map<string, vector<int>> positions;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++) {
            const string& key = wordsDict[i];
            positions[key].push_back(i);
        }

        for(auto & [_, posArray] : positions){
            sort(posArray.begin(), posArray.end());
        }
    }
    
    int shortest(string word1, string word2) {
        if(positions[word1].size() > positions[word2].size()){
            swap(word1, word2);
        }

        int smallestDistance = INT_MAX;
        for(const int idx : positions[word1]){
            //find closest value to idx
            const vector<int>& pos2 = positions[word2];

            const auto& ub = upper_bound(pos2.begin(), pos2.end(), idx);

            if(ub != pos2.begin()){
                const auto & smallerValue = prev(ub);
                int smallerIdx = *smallerValue;
                int distance = idx - smallerIdx;
                smallestDistance = min(smallestDistance, distance);
            }
            if(ub != pos2.end()){
                int largetIdx = *ub;
                int distance = largetIdx - idx;
                smallestDistance = min(smallestDistance, distance);
            }
        }

        return smallestDistance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */