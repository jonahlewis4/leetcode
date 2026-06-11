class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        
        vector<vector<int>> adjList(n);
        for(const vector<int>& edge : edges) {
            int v1 = edge.front();
            int v2 = edge.back();

            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }

        vector<int> indegree(n);
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++) {
            indegree[i] = adjList[i].size();
            if(indegree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> last;
        while(!q.empty()) {
            if(q.size() <= 2) {
                if(q.size() == 1) {
                    last = {q.front()};
                } else {
                    last = {q.front(), q.back()};
                }
            }
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int node = q.front();
                q.pop();

                for(int neigh : adjList[node]) {
                    indegree[neigh]--;
                    if(indegree[neigh] == 1) {
                        q.push(neigh);
                    }
                }
                
            }
        }

        return last;


    }
};