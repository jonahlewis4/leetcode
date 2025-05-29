class Solution {
private:
    tuple<unordered_set<int>, unordered_set<int>> nonAdjacent(const vector<vector<int>>& adjList) const {
        //returns two sets.
        //the sets contain all nodes which are not adjacent to each other based on the adjacency list.

        unordered_set<int> firstNonAdjacent;
        unordered_set<int> secondNonAdjacent;

        deque<int> q;
        q.push_back(0);

        bool first = true;
        while(!q.empty()){
            int n = q.size();
            unordered_set<int>& group = first ? firstNonAdjacent : secondNonAdjacent;
            
            for(int i = 0; i < n; i++){
                int node = q.front();
                q.pop_front();



                if(firstNonAdjacent.count(node) || secondNonAdjacent.count(node)){
                    continue;
                }

                group.insert(node);
                for(const auto & neigh : adjList[node]){
                    if(!firstNonAdjacent.count(node) && !secondNonAdjacent.count(node)){
                        continue;
                    }
                    q.push_back(neigh);
                }
            }
            first = !first;

        }
        return {firstNonAdjacent, secondNonAdjacent};
    }

    vector<vector<int>> getAdjList(vector<vector<int>>& edges) const {
        int n = edges.size() + 1;
        vector<vector<int>> adjList(n);
        for(const auto edge : edges) {
            int src = edge[0];
            int dest = edge[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        return adjList;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) const {
        const auto adjList1 = getAdjList(edges1);
        const auto adjList2 = getAdjList(edges2);
        
        vector<int> res(edges1.size() + 1);

        auto const& [first1, second1] = nonAdjacent(adjList1);
        auto const& [first2, second2] = nonAdjacent(adjList2);

        int bestBranchAcceptor = max(first2.size(), second2.size());

        for(int i = 0; i < adjList1.size(); i++){
            int nonAdjacent;
            if(first1.count(i)){
                nonAdjacent = first1.size();
            } else {
                nonAdjacent = second1.size();
            }
            res[i] = bestBranchAcceptor + nonAdjacent;
        }

        return res;
        
        
    }
};