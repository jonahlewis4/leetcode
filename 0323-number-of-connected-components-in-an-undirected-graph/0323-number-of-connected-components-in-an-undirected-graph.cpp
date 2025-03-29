class Solution {
private:
    class UnionFind{
        private:
            vector<int> nodes;
            vector<int> sizes;
            int size;
        public:
            UnionFind(int n ){
                nodes = vector<int>(n);
                for(int i = 0; i < n; i++){
                    nodes[i] = i;
                }
                sizes = vector<int>(n, 1);
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
                if(sizes[base1] > sizes[base2]){
                    nodes[base2] = base1;
                    sizes[base1] += sizes[base2];
                } else {
                    nodes[base1] = base2;
                    sizes[base2] += sizes[base1]; 
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