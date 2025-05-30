class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>> adjList(edges.size());

        for(int i = 0; i < edges.size(); i++){
            if(edges[i] == -1){
                continue;
            }
            adjList[i].push_back(edges[i]);
        }

        queue<int> q1;
        queue<int> q2;
        vector<bool> visit1(edges.size(), false);
        vector<bool> visit2(edges.size(), false);
        q1.push(node1);
        q2.push(node2);
        while(!q1.empty() || !q2.empty()){
            vector<int> neigh1;
            vector<int> neigh2;

            while(!q1.empty() || !q2.empty()){
                if(!q1.empty()){
                    int top = q1.back();
                    q1.pop();
                    //might not need this check
                    if(visit1[top]){
                        continue;
                    }
                    if(visit2[top]){
                        if(!q2.empty()){
                            int top2 = q2.back();
                            if(visit1[top2]){
                                if(top2 < top){
                                    return top2;
                                }
                            }
                        }
                        return top;
                    }
                    visit1[top] = true;
                    for(const auto & neigh : adjList[top]){
                        if(visit1[neigh]){
                            continue;
                        }
                        neigh1.push_back(neigh);
                    }
                }


                if(!q2.empty()){
                    int top = q2.back();
                    q2.pop();

                    if(visit2[top]){
                        continue;
                    }
                    if(visit1[top]){
                        return top;
                    }
                    visit2[top] = true;
                    for(const auto & neigh : adjList[top]){
                        if(visit2[neigh]){
                            continue;
                        }
                        neigh2.push_back(neigh);
                    }
                }
            }

            for(const auto & queued : neigh1 ){
                if(visit1[queued]){
                    continue;
                }
                q1.push(queued);
            }

            for(const auto & queued : neigh2) {
                if(visit2[queued]) {
                    continue;
                }
                q2.push(queued);
            }
        }
        return -1;
    }
};