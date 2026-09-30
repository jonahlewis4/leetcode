class Solution {
    class DSU {
        vector<int> root;
        vector<int> size;
        int numIslands;
    public:
        DSU(int n) {
            size.resize(n, 1);
            root.resize(n);
            iota(root.begin(), root.end(), 0);
            numIslands = n;
        }

        int find(int i){
            if(root[i] == i){
                return i;
            }
            int res = find(root[i]);
            root[i] = res;
            return res;
        }

        void merge(int a, int b) {
            int aRoot = find(a);
            int bRoot = find(b);
            if(aRoot == bRoot) {
                return;
            }

            if(size[aRoot] < size[bRoot]) {
                swap(aRoot, bRoot);
            }

            size[aRoot] += size[bRoot];
            root[bRoot] = aRoot;
            numIslands--;
        }


        int Size() {
            return numIslands;
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());
        for(int i = 0; i < isConnected.size(); i++) {
            for(int j = 0; j < isConnected.front().size(); j++) {
                if(isConnected[i][j]) {
                    dsu.merge(i, j);
                }
            }
        }
        return dsu.Size();
    }
};