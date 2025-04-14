class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //push lowest in lexi order of given node to stack. 
        //if top of stack has none in lexi order, pop from stack and put in answer.

        unordered_map<string, multiset<string>> list;
        for(auto const & t : tickets){
            const string & from = t[0];
            const string & to = t[1];
            list[from].insert(to);
        }

        stack<string> stack;
        stack.push("JFK");
        vector<string> res;
        while(!stack.empty()){
            string city = stack.top();
            if(list[city].empty()){
                stack.pop();
                res.push_back(city);
            } else {
                auto firstNeighItr = list[city].begin();
                stack.push(*firstNeighItr);
                list[city].erase(firstNeighItr);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};