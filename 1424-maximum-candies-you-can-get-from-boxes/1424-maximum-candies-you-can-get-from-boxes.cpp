class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int> foundNeedKeys;
        unordered_set<int> keysNotFound;
        for(int i = 0; i < status.size(); i++){
            if(status[i] == 1){
                keysNotFound.insert(i);
            }
        }

        queue<int> q;
        for(const auto & box : initialBoxes) {
            if(keysNotFound.count(box)){
                q.push(box);
                keysNotFound.erase(box);
            } else {
                foundNeedKeys.insert(box);
            }
        }

        int sum = 0;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            sum += candies[i];

            for(const auto & key : keys[i]){
                if(foundNeedKeys.count(key)){
                    q.push(key);
                    foundNeedKeys.erase(key);
                } else {
                    keysNotFound.insert(key);
                }
            }

            for(const auto & box : containedBoxes[i]){
                if(keysNotFound.count(box)){
                    q.push(box);
                    keysNotFound.erase(box);
                } else {
                    foundNeedKeys.insert(box);
                }
            }
        }
        return sum;
    }
};