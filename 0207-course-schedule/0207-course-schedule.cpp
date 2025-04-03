class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort.
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        for(const auto & prereq : prerequisites){
            adjList[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        int coursesVisited = 0;

        std::queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int course = q.front();
                q.pop();
                coursesVisited++;
                for(int neigh : adjList[course]){
                    indegree[neigh]--;
                    if(indegree[neigh] == 0){
                        q.push(neigh);
                    }
                }
            }
        }

        if(coursesVisited == numCourses){
            return true;
        }
        return false;
    }
};