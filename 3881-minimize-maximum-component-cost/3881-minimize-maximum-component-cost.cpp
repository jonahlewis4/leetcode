class Solution {
    class DSU{
        vector<int> root;
        vector<int> size;
        vector<int> largest;

        int numIslands;

    public:
        DSU(int n) {
            root.resize(n);
            iota(root.begin(), root.end(), 0);

            size.resize(n, 1);
            largest.resize(n, 0);
            numIslands = n;
        }

        int Find(int i){
            if(root[i] == i){
                return i;
            }

            root[i] = Find(root[i]);
            return root[i];
        }

        void Union(int a, int b, int edgeWeight) {
            int aRoot = Find(a);
            int bRoot = Find(b);

            if(aRoot == bRoot) {
                return;
            }

            numIslands--;
            if(size[aRoot] > size[bRoot]){
                size[aRoot] += size[bRoot];
                root[bRoot] = aRoot;
                largest[aRoot] = max({largest[aRoot], largest[bRoot], edgeWeight});
            } else {
                size[bRoot] += size[aRoot];
                root[aRoot] = bRoot;
                largest[bRoot] = max({largest[aRoot], largest[bRoot], edgeWeight});
            }
        }

        int Size() const {
            return numIslands;
        }

        int LargestEdge(int i) {
            int root = Find(i);
            return largest[root];
        }
    };
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](const vector<int>& edge1, const vector<int>& edge2){
            return edge1[2] < edge2[2];
        });

        DSU dsu(n);

        for(const vector<int>& edge : edges) {
            if(dsu.Size() <= k){
                break;
            }

            int v1 = edge[0];
            int v2 = edge[1];
            int weight = edge[2];

            dsu.Union(v1, v2, weight);
        }


        int best = 0;
        for(int i = 0; i < n; i++) {
            int root = dsu.Find(i);

            if(root == i) {
                best = max(best, dsu.LargestEdge(root));
            }
        }

        return best;
    }
};