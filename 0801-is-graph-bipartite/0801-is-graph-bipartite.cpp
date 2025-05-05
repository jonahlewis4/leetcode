class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        return _isBipartite(n, graph);
        // vector<bool> visited(n, false);

        // queue<int> q;

        // unordered_set<int> odd;
        // unordered_set<int> even;
        // int i = 0;
        // for(int p = 0; p < n; p++){
        
        //     if(visited[p]){
        //         continue;
        //     }
        //     if(q.empty()){
        //         i = 0;
        //         q.push(p);
        //     }
        //     int k = q.size();
        //     for(int j = 0; j < k; j++){
        //         unordered_set<int>* forbidden;
        //         unordered_set<int>* aggregator;
        //         if(i % 2 == 0){
        //             forbidden = &odd;
        //             aggregator = &even;
        //         } else {
        //             forbidden = &even;
        //             aggregator = &odd;
        //         }

        //         int node = q.front();
        //         q.pop();
        //         if(forbidden->find(node) != forbidden->end()){
        //             return false;
        //         }
        //         if(visited[node]){
        //             continue;
        //         }

        //         aggregator->insert(node);
        //         visited[node] = true;
        //         for(auto const & nei : graph[node]){
        //             if(aggregator->find(nei) != aggregator->end()){
        //                 return false;
        //             }
        //             if(visited[nei]){
        //                 continue;
        //             }

        //             q.push(nei);

        //         }
        //     }
        //     i++;
        // }   

        // return true;
    }

    bool _isBipartite(int n, const vector<vector<int>> &adjList){
        vector<int> colors(n, -1);
        for(int node = 1; node < n; node++){
            if(colors[node] != -1){
                continue;
            }
            queue<int> q;
            q.push(node);

            int color = false;
            while(!q.empty()){
                int n = q.size();
                for(int i = 0; i < n; i++){
                    int currentNode = q.front();
                    q.pop();
                    if(colors[currentNode] != -1 && colors[currentNode] != color){
                        return false;
                    } else if (colors[currentNode] != -1){
                        continue;
                    }
                    colors[currentNode] = color;
                    for(int neigh : adjList[currentNode]){
                        if(colors[neigh] != -1 && colors[neigh] == colors[currentNode]){
                            return false;
                        } else if (colors[neigh] != -1){
                            continue;
                        }
                        q.push(neigh);
                    }
                }
                color = !color;
            }
        }
        return true;
    }
};