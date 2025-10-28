class Solution {
    class DSU{
        vector<int> root;
        vector<int> size;

        int numIslands;
    public:
        DSU(int n) {
            root.resize(n);
            iota(root.begin(), root.end(), 0);

            size.resize(n, 1);
            numIslands = n;
        }

        int Find(int i){
            if(root[i] == i){
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
            numIslands--;
            if(size[aRoot] > size[bRoot]){
                size[aRoot] += size[bRoot];
                root[bRoot] = aRoot;
            } else {
                size[bRoot] += size[aRoot];
                root[aRoot] = bRoot;
            }

        }

        int Size() const {
            return numIslands;
        }

        
    };
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](const vector<int>& edge1, const vector<int>& edge2){
            return edge1[2] > edge2[2];
        });

        DSU dsu(n);

        for(const vector<int>& edge : edges) {
            dsu.Union(edge[0], edge[1]);

            if(dsu.Size() < k){
                return edge[2];
            }
        }

        return 0;
    }
};