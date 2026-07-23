class Solution {
    pair<int, int> e(int stage, int firstPlayer, int secondPlayer) {
        int playerCount = playersInStage[stage];
        if(firstPlayer == playerCount - secondPlayer - 1){
            return {stage, stage};
        }       

        if(eCache[stage][firstPlayer][secondPlayer] != -1) {
            return {eCache[stage][firstPlayer][secondPlayer], lCache[stage][firstPlayer][secondPlayer]};
        }

        queue<pair<int, int>> q;
        q.push({0,0});
        for(int i = 0; i < playerCount / 2; i++) {
            int n = q.size();
            for(int j = 0; j < n; j++) {
                pair<int, int> delta = q.front();
                q.pop();

                if(i == firstPlayer) {
                    int firstMatch = playerCount - i - 1;
                    if(firstMatch < secondPlayer) {
                        q.push({delta.first, delta.second - 1});
                    } else {
                        q.push({delta.first, delta.second});
                    }
                } else if (i == secondPlayer) {
                    //second player is after first player, so we know
                    //for absolute certain that nothing will be deleted 
                    //before first OR second
                    q.push({delta.first, delta.second});
                } else if (i == playerCount - firstPlayer - 1) {
                    //if i is firstMatch
                    //delete one from both, because analog comes before each
                    q.push({delta.first - 1, delta.second - 1});
                } else if (i == playerCount - secondPlayer - 1) {
                    //if i is secondMatch
                    
                    if(i < firstPlayer) {
                        q.push({delta.first - 1, delta.second - 1});
                    } else {
                        q.push({delta.first, delta.second - 1});
                    }
                } else {
                    int comp = playerCount - i - 1;

                    if(i < firstPlayer) {
                        q.push({delta.first-1, delta.second - 1});
                    } else if (i < secondPlayer) {
                        q.push({delta.first, delta.second - 1});
                    } else {
                        q.push({delta.first, delta.second});
                    }

                    if(comp < firstPlayer) {
                        q.push({delta.first-1, delta.second - 1});
                    } else if (comp < secondPlayer) {
                        q.push({delta.first, delta.second - 1});
                    } else {
                        q.push({delta.first, delta.second});
                    }
                }
            }
        }

        pair<int, int> res = {INT_MAX, 0};
        while(!q.empty()) {
            pair<int, int> delta = q.front();
            q.pop();
            
            pair<int, int> attempt = e(stage + 1, firstPlayer + delta.first, secondPlayer + delta.second);
            res.first = min(attempt.first, res.first);
            res.second = max(attempt.second, res.second);
        }
        tie(eCache[stage][firstPlayer][secondPlayer], lCache[stage][firstPlayer][secondPlayer]) = res;
        return res;
    }

    vector<int> playersInStage;

    vector<vector<vector<int>>> eCache;
    vector<vector<vector<int>>> lCache;
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        //TODO: merge e and l functions
        
        if(secondPlayer < firstPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        for(;n > 1; n = (n+1)/2) {
            playersInStage.push_back(n);
        }

        //create a lookup area mapping stage to number of remaining players

        eCache.resize(playersInStage.size(), vector<vector<int>>(firstPlayer, vector<int>(secondPlayer, -1)));
        lCache.resize(playersInStage.size(), vector<vector<int>>(firstPlayer, vector<int>(secondPlayer, -1)));

        pair<int, int> p = e(0, firstPlayer-1, secondPlayer-1);

        return {p.first + 1, p.second + 1};
    }
};