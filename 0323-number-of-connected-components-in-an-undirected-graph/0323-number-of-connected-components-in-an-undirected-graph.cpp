class Solution {
private:
    class Dsu{
        struct Node{
            int parentId;
            int size = 1;
        };

        int connections;
        vector<Node> nodes;
    public:
        Dsu(int n){
            nodes.resize(n);
            for(int i = 0; i < nodes.size(); i++){
                nodes[i].parentId = i;
            }
            connections = n;
        }

        int Find(int i){
            if(nodes[i].parentId == i){
                return i;
            }
            nodes[i].parentId = Find(nodes[i].parentId);
            return nodes[i].parentId;

        }

        void Union(int a, int b) {
            int rootIdA = Find(a);
            int rootIdB = Find(b);

            if(rootIdA == rootIdB){
                return;
            }

            Node &nodeA = nodes[rootIdA];
            Node &nodeB = nodes[rootIdB];
            connections--;

            if(nodeA.size < nodeB.size){
                nodeB.size += nodeA.size;
                nodeA.parentId = nodeB.parentId;
            } else {
                nodeA.size += nodeB.size;
                nodeB.parentId = nodeA.parentId;
            }
        }

        int Size() const {
            return connections;
        }

    };
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Dsu dsu(n);
        for(const auto & edge : edges){
            dsu.Union(edge[0], edge[1]);
        }
        return dsu.Size();

    }
};