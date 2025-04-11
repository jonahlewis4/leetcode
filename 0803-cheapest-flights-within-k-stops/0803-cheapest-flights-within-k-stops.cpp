class Solution {

    struct stop {
        int stops;
        int node;
        int weight;
    };

    struct edge {
        int to;
        int weight;
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {


        //djikstra's
        //track distances for each node at each stop amount
        //only push if at that stop amount 
        //if node == dst, return the amount because the first time we reach k will be from the minimum weight.
        //if stops >= k and we aren't at dst, we can't go further.
        //push values only if they are smaller than the distance at the new stop amount and node.


        //create adjacency list
        unordered_map<int, vector<edge>> adjList;
        for(const auto & flight : flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adjList[from].push_back({
                .to = to,
                .weight = price
            });
        } 


        vector<vector<int>> dst(n, vector<int>(k + 2, INT_MAX));

        priority_queue<stop, vector<stop>, decltype([](const auto & a, const auto & b){
            //return true if a has LOWER priority than b.
            //lower priority is if a has larger weight.
            //tiebreaker: if they have the same weight, give a lower priority if the stops is larger.

            if(a.weight > b.weight){
                return true;
            }
            if(a.weight == b.weight){
                return a.stops > b.stops;
            }
            return false;
        })> pq;

        pq.push({
            .stops = 0,
            .node = src,
            .weight = 0
        });

        while(!pq.empty()){
            stop s = pq.top();
            pq.pop();
            if(s.stops <= k + 1 && s.node == dest){
                return s.weight;
            } 
            if(s.stops > k || s.weight > dst[s.node][s.stops]){
                continue;
            }

            for(const auto & edge : adjList[s.node]){
                //if smaller update.
                //push with 1 higher stops
                //do not push if to != src and new stops >= k

                int newWeight = s.weight + edge.weight;
                if(newWeight < dst[edge.to][s.stops + 1]){
                    dst[edge.to][s.stops + 1] = newWeight;
                    //only push if stops allow
                    pq.push({
                        .stops = s.stops + 1,
                        .node = edge.to,
                        .weight = newWeight
                    });
                } 
            }
        }

        return -1;

        

    



    }
};