class Solution {
    class DSU {
        vector<int> root;
        vector<int> size;

    public:
        DSU(int n) {
            root.resize(n);
            size.resize(n, 1);
            iota(root.begin(), root.end(), 0);
        }

        int Find(int i) {
            if(root[i] == i) {
                return i;
            }

            root[i] = Find(root[i]);
            return root[i];
        }

        void Union(int a, int b) {
            int aRoot = Find(a);
            int bRoot = Find(b);

            if(aRoot == bRoot) {
                return;
            }

            if(size[aRoot] > size[bRoot]){
                root[bRoot] = aRoot;
                size[aRoot] += size[bRoot];
            } else {
                root[aRoot] = bRoot;
                size[bRoot] += size[aRoot];
            }
        }
    };
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for(const vector<int>& con : connections) {
            dsu.Union(con[0] - 1, con[1] - 1);
        }

        vector<vector<int>> connectedTo(c);
        vector<unordered_set<int>> exists(c);
        
        for(int i = c - 1; i >= 0; i--) {
            int root = dsu.Find(i);
            connectedTo[root].push_back(i);
            exists[root].insert(i);
        }

        

        vector<int> res;

        for(const vector<int>& q : queries){
            int type = q[0];
            if(type == 1) {
                int station = q[1];
                int root = dsu.Find(station - 1);

                vector<int>& connections = connectedTo[root];
                const unordered_set<int>& exist = exists[root];
                while(!connections.empty() && !exist.contains(connections.back())){
                    connections.pop_back();
                }


                if(exist.contains(station - 1)){ 
                    res.push_back(station);
                } else if (connections.empty()){ 
                    res.push_back(-1);
                } else {
                    res.push_back(connections.back() + 1);
                }
            } else {
                int station = q[1];
                int root = dsu.Find(station - 1);
                unordered_set<int>& exist = exists[root];
                exist.erase(station - 1);
            }
        }


        return res;

    }
};