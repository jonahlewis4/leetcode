class Solution {
    class DSU{
        vector<int> root;
        vector<int> size;
    public:
        DSU(int n) {
            root.resize(n, -1);
            size.resize(n, 1);
            iota(root.begin(), root.end(), 0);
        
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

            //make sure aRoot is the larger one and merge bRoot into aRoot
            if(size[aRoot] < size[bRoot]){
                swap(aRoot, bRoot);
            }

            size[aRoot] += size[bRoot];
            root[bRoot] = aRoot;
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
        return sum;
        
    }

    int possibleGroups(int node, const vector<vector<int>> &adjList){
        vector<int8_t> colors(adjList.size(), -1);
        queue<int> q;
        q.push(node);

        int color = false;
        int groups = 0;
        while(!q.empty()){
            groups++;
            int n = q.size();
            for(int i = 0; i < n; i++){
                int currentNode = q.front();
                dsu.Union(currentNode, node);

                q.pop();
                if(colors[currentNode] != -1 && colors[currentNode] != color){
                    return -1;
                } else if (colors[currentNode] != -1){
                    continue;
                }
                colors[currentNode] = color;
                for(int neigh : adjList[currentNode]){
                    if(colors[neigh] != -1 && colors[neigh] == colors[currentNode]){
                        return -1;
                    } else if (colors[neigh] != -1){
                        continue;
                    }
                    q.push(neigh);
                }
            }
            color = !color;
        }
        return groups;
    }

        
};