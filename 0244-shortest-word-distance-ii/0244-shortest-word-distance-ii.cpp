class WordDistance {
    unordered_map<string, vector<int>> positions;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++) {
            const string& key = wordsDict[i];
            positions[key].push_back(i);
        }
    }
    
    int shortest(const string& word1, const string& word2) {
        int smallestDistance = INT_MAX;
        
        const vector<int>& pos1 = positions[word1];
        const vector<int>& pos2 = positions[word2];

        int i1 = 0;
        int i2 = 0;
        while(i1 < pos1.size() && i2 < pos2.size()){
            int dist = abs(pos1[i1] - pos2[i2]);
            smallestDistance = min(smallestDistance, dist);

            if(pos1[i1] > pos2[i2]){
                i2++;
            } else {
                i1++;
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