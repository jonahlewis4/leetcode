class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        return _isBipartite(n, graph);
    }

    inline bool _isBipartite(int n, const vector<vector<int>> &adjList){
        vector<int8_t> colors(n, -1);
        for(int node = 1; node < n; node++){
            if(!isBipartite(node, adjList, colors)){
                return false;
            }
        }
        
        return true;
    }

    bool isBipartite(int node, const vector<vector<int>> &adjList, vector<int8_t> &colors){
        if(colors[node] != -1){
            return true;
        }
        queue<int> q;
        q.push(node);

        int color = false;

        int edgeNode;
        colors[node] = color;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){

                int currentNode = q.front();

                q.pop();
                if(colors[currentNode] != color){
                    return false;
                } 

                edgeNode = currentNode;

                colors[currentNode] = color;
                for(int neigh : adjList[currentNode]){
                    if(colors[neigh] != -1 && colors[neigh] == colors[currentNode]){
                        return false;
                    } else if (colors[neigh] != -1){
                        continue;
                    }
                    colors[neigh] = !color;

                    q.push(neigh);
                }
            }
            color = !color;
        }

        return true;
    }

};