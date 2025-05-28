class Solution {
private:
    int bfs(vector<vector<int>>& adjList, int start, int maxDepth) const {
        deque<int> q;
        //we can use up to and including maxDepth.
        q.push_front(start);
        int count = 0;
        vector<bool> visited(adjList.size(), false);
        for(int i = 0; i <= maxDepth; i++){
            if(q.empty()){
                return count; 
            }

            int n = q.size();
            for(int j = 0; j < n; j++){
                int node = q.front();
                q.pop_front();
                if(visited[node]){
                    continue;
                }
                visited[node] = true;
                count++;

                for(const auto & neigh : adjList[node]){
                    if(!visited[neigh]){
                        q.push_back(neigh);
                    }
                }
            }
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
            int neigh = bfs(adjList2, i, k - 1);
            bestTree2Count = max(bestTree2Count, neigh);
        }

        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int neigh = bfs(adjList1, i, k);
            res[i] = neigh + bestTree2Count;
        }

        return res;
    }
};