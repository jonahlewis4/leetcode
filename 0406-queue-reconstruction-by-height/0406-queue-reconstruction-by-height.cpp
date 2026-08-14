class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        unordered_map<int, int> gte;
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++) {
            vector<int> best = {INT_MAX};
            int bestI;
            for(int j = 0; j < people.size(); j++) {
                int height = people[j].front();
                if(height == -1) {
                    continue;
                }
                int targetGte = people[j].back();
                
                if(gte[height] == targetGte) {
                    if(best.front() > height){
                        best = people[j];
                        bestI = j;
                    }
                }
            }
            res.push_back(best);

            int bestHeight = best.front();
            
            for(auto& [key, count]: gte) {
                if(key <= bestHeight){
                    count++;
                }
            }
            people[bestI].front() = -1;
        }

        return res;
    }
};