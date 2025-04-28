class Solution {
    struct node {
        int id;
        int indegree = 0;
        int importance = 0;
    };
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> edges;
        for(auto const & road : roads){
            edges[road[0]]++;
            edges[road[1]]++;
        }

        vector<node> nodes(n);
        for(auto const & p : edges){
            nodes[p.first] = {
                .id = p.first,
                .indegree = p.second,
            };
        }
        auto oldNodes = nodes;
        sort(nodes.begin(), nodes.end(), [](auto const & a, auto const & b){
            return a.indegree < b.indegree;
        });

        long long sum = 0;

        for(int i = 0; i < n; i++){
            oldNodes[nodes[i].id].importance = i + 1;
        }

        for(auto const & edge : roads){
            int src = edge[0];
            int dest = edge[1];

            sum += oldNodes[src].importance + oldNodes[dest].importance;
        }

        return sum;


    }
};