class Solution {
private:
    unordered_map<string, multiset<string>> list;
    vector<string> res;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //recursive version

        for(auto const & t : tickets){
            const string & from = t[0];
            const string & to = t[1];
            list[from].insert(to);
        }

        dfs("JFK");

        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(const string & city){
        while(!list[city].empty()){
            auto firstNeighItr = list[city].begin();
            string next = *firstNeighItr;
            list[city].erase(firstNeighItr);
            dfs(next);
        }
        res.push_back(city);
        return;
    }
};