class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int trainI = 0;
        int matches = 0;
        for(const auto & ability : players) {
            int capacity = trainers[trainI];

            while(trainI < trainers.size() && ability > trainers[trainI]){
                trainI++;
            }
            if(trainI == trainers.size()) {
                break;
            }
            matches++;
            trainI++;
        }
        return matches;
    }
};