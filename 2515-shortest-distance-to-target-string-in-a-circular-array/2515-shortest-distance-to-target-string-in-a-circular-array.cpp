class Solution {
    int customDiff(int n, int foundI, int startI){
        if(startI > foundI) {
            swap(foundI, startI);
        }
        // cout<<foundI<<endl;
        // cout<<startI<<endl;
        int firstWay = ((foundI - startI) + n) % n;
        return std::min(firstWay, n - firstWay);
    }
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int closest = INT_MAX;
        for(int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            if(target == word) {
                int dist = customDiff(words.size(), i, startIndex);
                closest = min(dist, closest);
            }
        }

        if(closest == INT_MAX) {
            return -1;
        }


        return closest;
        
    }
};