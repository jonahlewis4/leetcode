class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.empty()){
            return 0;
        }
        int n = INT_MIN;
        for(const auto & edge: edges){
            n = max({edge[0], edge[1], n});
        }
        n++;
        vector<vector<int>> adjList(n);
        for(const auto & edge :edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return diameter(0, adjList);
    }

    int diameter (int any, const vector<vector<int>> &adjList){
        queue<int> q;
        q.push(any);
        vector<bool> visited(adjList.size(), false);
        visited[any] = true;
        int edge;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int cur = q.front();
                edge = cur;
                q.pop();
                for(const auto &neigh : adjList[cur]){
                    if(visited[neigh]){
                        continue;
                    }
                    visited[neigh] = true;
                    q.push(neigh);
                }

            }
        }

        q = queue<int>();
        q.push(edge);
        visited = vector<bool>(adjList.size(), false);
        visited[edge] = true;
        int len = 0;
        while(!q.empty()){
            len++;
            int n = q.size();
            for(int i = 0; i < n; i++){
                int cur = q.front();
                edge = cur;
                q.pop();
                for(const auto &neigh : adjList[cur]){
                    if(visited[neigh]){
                        continue;
                    }
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return len - 1;
    }
};