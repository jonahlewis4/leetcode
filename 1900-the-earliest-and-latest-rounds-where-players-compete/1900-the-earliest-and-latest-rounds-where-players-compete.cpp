class Solution {
    int e(int stage, int firstPlayer, int secondPlayer) {
        int playerCount = playersInStage[stage];
        if(firstPlayer == playerCount - secondPlayer - 1){
            return stage;
        }       

        if(eCache[stage][firstPlayer][secondPlayer] != -1) {
            return eCache[stage][firstPlayer][secondPlayer];
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

        int res = INT_MAX;
        while(!q.empty()) {
            pair<int, int> delta = q.front();
            q.pop();
            
            int attempt = e(stage + 1, firstPlayer + delta.first, secondPlayer + delta.second);
            res = min(attempt, res);
        }
        eCache[stage][firstPlayer][secondPlayer] = res;
        return res;
    }

    int l(int stage, int firstPlayer, int secondPlayer) {
        int playerCount = playersInStage[stage];
        if(firstPlayer == playerCount - secondPlayer - 1){
            return stage;
        }

        if(lCache[stage][firstPlayer][secondPlayer] != -1) {
            return lCache[stage][firstPlayer][secondPlayer];
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

        int res = 0;
        while(!q.empty()) {
            pair<int, int> delta = q.front();
            q.pop();
            
            int attempt = l(stage + 1, firstPlayer + delta.first, secondPlayer + delta.second);
            res = max(attempt, res);
        }
        lCache[stage][firstPlayer][secondPlayer] = res;
        return res;
    }

    vector<int> playersInStage;

    vector<vector<vector<int>>> eCache;
    vector<vector<vector<int>>> lCache;
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if(secondPlayer < firstPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        for(;n > 1; n = (n+1)/2) {
            playersInStage.push_back(n);
        }

        //create a lookup area mapping stage to number of remaining players

        eCache.resize(playersInStage.size(), vector<vector<int>>(firstPlayer, vector<int>(secondPlayer, -1)));
        lCache.resize(playersInStage.size(), vector<vector<int>>(firstPlayer, vector<int>(secondPlayer, -1)));

        int earliest = e(0, firstPlayer-1, secondPlayer-1);
        int latest = l(0, firstPlayer-1, secondPlayer-1);

        return {earliest + 1, latest + 1};
    }
};