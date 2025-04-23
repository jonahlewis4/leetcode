class Solution {
struct edge {
    int dest;
    int weight;
};
class cmpByWeight{
public:
    bool operator()(const auto & a, const auto & b){
        //return true if a has lower priority
        return a.weight > b.weight;
    }
};
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> adjList(n + 1);
        for(auto const & time : times){
            int src = time[0];
            int dest = time[1];
            int weight = time[2];
            adjList[src].push_back({
                .dest = dest,
                .weight = weight
            });
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<edge, vector<edge>, cmpByWeight> pq;
        pq.push({
            .dest = k,
            .weight = 0
        });

        while(!pq.empty()){
            edge e = pq.top();
            pq.pop();
            if(e.weight >= dist[e.dest]){
                continue;
            }
            dist[e.dest] = e.weight;
            for(auto const & n : adjList[e.dest]){
                int newWeight = e.weight + n.weight;
                if(newWeight < dist[n.dest]){
                    pq.push({
                        .dest = n.dest,
                        .weight = newWeight
                    });
                }
            }
        }

        //get the max from the distances.
        int maxDistance = -1;
        for(int i = 1; i < dist.size(); i++){
            maxDistance = max(dist[i], maxDistance);
        }

        //return -1 if one of the nodes has not been visited (if it is INT_MAX)
        return maxDistance == INT_MAX ? -1 : maxDistance;
    }

};