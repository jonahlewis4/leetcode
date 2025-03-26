class Solution {
private:
    struct Node {
        int indegree = 0;
        vector<int> neighboors;
    };
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res(numCourses);
        vector<Node> adj(numCourses);
        for(const auto & prereq : prerequisites){
            int dependent = prereq[0];
            int required = prereq[1];

            adj[dependent].indegree++;
            adj[required].neighboors.push_back(dependent);
        }

        queue<int> queue;
        for(int i = 0; i < adj.size(); i++){
            if(adj[i].indegree == 0){
                queue.push(i);
            }
        }

        int completed = 0;
        while(!queue.empty()){
            int nodeIdx = queue.front();
            queue.pop();
            res[completed] = nodeIdx;
            completed++;

            for(const int neigh : adj[nodeIdx].neighboors){
                adj[neigh].indegree--;
                if(adj[neigh].indegree == 0){
                    queue.push(neigh);
                }
            }
        }

        if(completed == numCourses){
            return res;
        } else {
            return {};
        }
    }
};