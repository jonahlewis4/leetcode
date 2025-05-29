class Solution {
private:
    enum color{
        NOT_YET_COLORED = -1,
        BLACK = 0,
        WHITE = 1,
    };
    tuple<vector<color>, int, int> nonAdjacent(const vector<vector<int>>& adjList) const {
        //returns two sets.
        //the sets contain all nodes which are not adjacent to each other based on the adjacency list.

        

        deque<int> q;
        q.push_back(0);

        bool first = true;
        vector<color> colors(adjList.size(), NOT_YET_COLORED);
        while(!q.empty()){
            int n = q.size();            
            color color = first ? BLACK : WHITE;
            for(int i = 0; i < n; i++){
                int node = q.front();
                q.pop_front();

                

                if(colors[node] != NOT_YET_COLORED){
                    continue;
                }

                colors[node] = color;
                for(const auto & neigh : adjList[node]){
                    if (colors[neigh] != NOT_YET_COLORED) {
                        continue;  
                    }
                    q.push_back(neigh);
                }
            }
            first = !first;

        }
        int whiteCount = 0;
        int blackCount = 0;
        for(const auto & color : colors ){
            if(color == BLACK){
                blackCount++;
            } else {
                whiteCount++;
            }
        }
        return {colors, blackCount, whiteCount};
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

        auto const& [colors, blackCount, whiteCount] = nonAdjacent(adjList1);
        auto const& [_, blackCount2, whiteCount2] = nonAdjacent(adjList2);

        int bestBranchAcceptor = max(blackCount2, whiteCount2);

        for(int i = 0; i < adjList1.size(); i++){
            int nonAdjacent;
            if(colors[i] == BLACK){
                nonAdjacent = blackCount;
            } else {
                nonAdjacent = whiteCount;
            }
            res[i] = bestBranchAcceptor + nonAdjacent;
        }

        return res;
    }
};