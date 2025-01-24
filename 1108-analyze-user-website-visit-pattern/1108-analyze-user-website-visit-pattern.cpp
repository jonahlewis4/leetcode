class Solution {
private: struct visit{
    string username;
    int timestamp;
    string website;
};
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        std::unordered_map<string, unordered_map<string, unordered_map<string, int>>> patterns;

        std::unordered_map<string, vector<string>> users;
        

        std::vector<visit> visits(username.size());
        for(int i = 0; i < visits.size(); i++){
            visits[i] = {
                .username = username[i],
                .timestamp = timestamp[i],
                .website = website[i]
            };
        }

        sort(visits.begin(), visits.end(), [](visit & a, visit & b){
            return a.timestamp < b.timestamp;
        });


        for(const auto & visit : visits){
            users[visit.username].push_back(visit.website);
        }

        for(auto & userPair : users){
            //string userName = userPair.first;
            vector<string>& websites = userPair.second;
            unordered_map<string, unordered_map<string, unordered_set<string>>> used;

            for(int i = 0; i < websites.size(); i++){
                for(int j = i + 1; j < websites.size(); j++){
                    for(int k = j + 1; k < websites.size(); k++){
                        if(used[websites[i]][websites[j]].find(websites[k]) == used[websites[i]][websites[j]].end()){
                            patterns[websites[i]][websites[j]][websites[k]]++;
                            used[websites[i]][websites[j]].insert(websites[k]);
                        }
                    }
                }
            }
        }

        vector<string> mostVisited;
        int mostVisitedScore = 0;
        for(const auto & pattern : patterns){
            string s1 = pattern.first;
            for(const auto & pattern : pattern.second){
                string s2 = pattern.first;
                for(const auto & pattern : pattern.second){
                    string s3 = pattern.first;
                    if(pattern.second > mostVisitedScore || (pattern.second == mostVisitedScore && (lexiLess(s1, s2, s3, mostVisited)))){
                        mostVisitedScore = pattern.second;
                        mostVisited = {s1, s2, s3};
                    }
                }
            }
        }
        return mostVisited;

    }
    bool lexiLess(const string &s1,const string &s2, const string &s3, const vector<string> & mostVisited){
        if(mostVisited.size() == 0){
            return true;
        }
        if(s1 < mostVisited[0]){
            return true;
        }
        if(s1 > mostVisited[0]){
            return false;
        }
        if(s2 < mostVisited[1]){
            return true;
        }
        if(s2 > mostVisited[1]){
            return false;
        }
        if(s3 < mostVisited[2]){
            return true;
        }
        return false;
    }
};