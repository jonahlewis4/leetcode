class Solution {
private:
    int dfs(vector<vector<int>>& adjList, int start, int maxDepth) const {
        deque<int> q;
        //we can use up to and including maxDepth.
        vector<bool> visited(adjList.size(), false);
        return _dfs(adjList, start, 0, maxDepth, visited);
    }

    int _dfs(vector<vector<int>>& adjList, int start, int depth, int maxDepth, vector<bool>& visited) const {
        if(visited[start]){
            return 0;
        }
        if(depth > maxDepth) {
            return 0;
        }

        visited[start] = true;

        int count = 1;
        for(const auto & neigh : adjList[start]){
            count += _dfs(adjList, neigh, depth + 1, maxDepth, visited);
        }
        return count;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        //find node in edges2 with most neighboors within k.

        vector<vector<int>> adjList1(n);
        for(const auto & edge : edges1){
            int src = edge[0];
            int dest = edge[1];
            adjList1[src].push_back(dest);
            adjList1[dest].push_back(src);
        }


        vector<vector<int>> adjList2(m);
        for(const auto & edge : edges2){
            int src = edge[0];
            int dest = edge[1];
            adjList2[src].push_back(dest);
            adjList2[dest].push_back(src);
        }


        int bestTree2Count = 0;
        for(int i = 0; i < m; i++){
            int neigh = dfs(adjList2, i, k - 1);
            bestTree2Count = max(bestTree2Count, neigh);
        }

        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int neigh = dfs(adjList1, i, k);
            res[i] = neigh + bestTree2Count;
        }

        return res;
    }
};