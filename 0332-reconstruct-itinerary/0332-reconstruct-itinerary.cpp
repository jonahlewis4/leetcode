class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //multiset: is ordered and such. 
        unordered_map<string, multiset<string>> adjList;
        for(const auto & ticket : tickets) {
            string src = ticket[0];
            string dest = ticket[1];
            adjList[src].insert(dest);
        }

        //when we reach a node with no neighboors, push to stack
        stack<string> stack;
        stack.push("JFK");
        vector<string> res;
        while(!stack.empty()){
            string cur = stack.top();
            if(adjList[cur].empty()){
                res.push_back(cur);
                stack.pop();
                continue;
            }
            auto begin = adjList[cur].begin();
            stack.push(*begin);
            adjList[cur].erase(begin);

        }





        //reverse the result and return. 
        reverse(res.begin(), res.end());
        return res;


    }
};