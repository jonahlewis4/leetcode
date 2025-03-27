class Solution {
private:
vector<vector<int>> adjList;
vector<bool> visited;
int visitCount = 0;

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //is there a cycle in this undirected graph.

        //simple dfs with visited array.

        //if at the end we haven't visited every node, return false.

        if(edges.size() != n - 1){
            return false;
        }


        adjList = vector<vector<int>>(n);
        for(const auto & edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            // if(node1 > node2){
            //     swap(node1, node2);
            // }
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        
        visited = vector<bool>(n, false);
        int i = 0;
        auto visitedCount = &visitCount;
        dfs(0);
        if(visitCount != n){
            return false;
        }
        return true;
        

        

    }
    void dfs(int nodeIdx){
        if(visited[nodeIdx]){
            return;
        }
        visitCount++;
        visited[nodeIdx] = true;
        for(const int neigh : adjList[nodeIdx]){
            dfs(neigh);
        }


    }
        
};