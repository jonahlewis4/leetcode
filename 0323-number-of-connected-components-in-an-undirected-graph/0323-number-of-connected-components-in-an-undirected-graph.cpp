class Solution {
private:
    class UnionFind{
        private:
            vector<int> nodes;
            vector<int> rank;
            int size;
        public:
            UnionFind(int n ){
                nodes = vector<int>(n);
                for(int i = 0; i < n; i++){
                    nodes[i] = i;
                }
                rank = vector<int>(n, 1);
                size = n;
            }

            int Find(int n) {
                if(nodes[n] == n){
                    return n;
                } else {
                    nodes[n] = Find(nodes[n]);
                }
                return nodes[n];
            }

            void Union(int n1, int n2){
                int base1 = Find(n1);
                int base2 = Find(n2);

                if(base1 == base2){
                    return;
                } 


                //add the smaller rank to the larger rank
                if(rank[base1] > rank[base2]){
                    nodes[base2] = base1;
                } else if (rank[base2] > rank[base1]){
                    nodes[base1] = base2;
                } else {
                    nodes[base1] = base2;
                    rank[base2]++;
                }
                size--;

            }

            int Size() const {
                return size;
            }

    };

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind u(n);
        for(const auto & edge : edges){
            u.Union(edge[0], edge[1]);
        }
        return u.Size();
    }
};