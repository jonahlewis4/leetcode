class Solution {
    class DSU{
        vector<int> root;
        vector<int> size;

        int _size;
    public:
        DSU(int n) {
            root.resize(n, -1);
            size.resize(n, 1);
            iota(root.begin(), root.end(), 0);
            _size = n;
        }
        DSU(){

        }

        int Find(int i){
            if(root[i] == i){
                return i;
            }
            root[i] = Find(root[i]);
            return root[i];
        }

        void Union(int a, int b){
            auto & root = this->root;
            int aRoot = Find(a);
            int bRoot = Find(b);

            if(aRoot == bRoot){
                return;
            }
            _size--;
            //make sure aRoot is the larger one and merge bRoot into aRoot
            if(size[aRoot] < size[bRoot]){
                swap(aRoot, bRoot);
            }

            size[aRoot] += size[bRoot];
            root[bRoot] = aRoot;
        }

        void Reduce(){
            for(int i = 0; i < root.size(); i++){
                root[i] = Find(i);
            }
        }

        vector<int> Roots(){
            Reduce();
            vector<int> res;
            for(int i = 0; i < root.size(); i++){
                if(root[i] == i){
                    res.push_back(i);
                }
            }
            return res;
        }

        vector<int> Nodes() const {
            return root;
        }
        vector<int> Sizes() const {
            return size;
        }

        int Size() const {
            return _size;
        }
    };

    DSU dsu;
    
public:
    int magnificentSets(int n, vector<vector<int>>& _edges) {
        //find if there is a cascade of nodes distance d, d - 1, d - 2, .. 1 from any given node.

        vector<vector<int>> adjList(n + 1);
        for(int i = 0; i < _edges.size(); i++){
            const auto & edge = _edges[i];
            int v1 = edge[0];
            int v2 = edge[1];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }


        dsu = DSU(n + 1);
        unordered_map<int, int> largestOfGroup;

        vector<int8_t> colors(n + 1, -1);
        for(int i = 1; i <= n; i++){
            if(!isBipartite(i, adjList, colors)){
                return -1;
            }
        }


        for(int i = 1; i <= n; i++){
            int length = possibleGroups(i, adjList);
            if(length == -1){
                return -1;
            }
            largestOfGroup[dsu.Find(i)] = max(largestOfGroup[dsu.Find(i)], length);
        }

        int sum = 0;
        for(const auto & p : largestOfGroup){
            sum += p.second;
        }

        // cout<<"DSU size: "<<dsu.Size()<<endl;
        // auto roots = dsu.Roots();
        // auto nodes = dsu.Nodes();
        // auto sizes = dsu.Sizes();
        return sum;
        
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
                dsu.Union(currentNode, node);

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

    int possibleGroups(int node, const vector<vector<int>> &adjList){
        return diameter(node, adjList);
    }

    int diameter (int any, const vector<vector<int>> &adjList){
        queue<int> q;
        q.push(any);
        vector<bool> visited(adjList.size(), false);
        visited[any] = true;
        int edge = any;
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
            len++;

        }
        return len;
    }

        
};