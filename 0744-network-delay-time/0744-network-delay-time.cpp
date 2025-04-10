class Solution {
private:
    struct edgeDest{
        int node;
        int weight;
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<edgeDest>> adjList;
        for(const auto & time : times){
            int node1 = time[0];
            int node2 = time[1];
            int weight = time[2];
            adjList[node1].push_back({
                .node = node2,
                .weight = weight
            });
        }  

        auto cmp = [](const auto & a, const auto & b){
            if(a.weight < b.weight){
                return true;
            }
            return a.node < b.node;
        };
        set<edgeDest, decltype(cmp)> set;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        set.insert({
            .node = k,
            .weight = 0
        });
        while(!set.empty()){
            auto begin = set.begin();
            edgeDest e = *begin;
            set.erase(begin);



            for(auto const & neigh : adjList[e.node]){
                int newWeight = neigh.weight + e.weight;

                if(newWeight < dist[neigh.node]){
                    if(dist[neigh.node] != INT_MAX){
                        set.erase({neigh.node, dist[neigh.node]});
                    }
                    dist[neigh.node] = newWeight;
                    set.insert({
                        .node = neigh.node,
                        .weight = newWeight
                    });
                }
            }
        }



        int res = -1;
        for(int i = 1; i < dist.size(); i++){
            res = max(res, dist[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};