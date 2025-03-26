class Solution {
private:
struct node{
    unordered_set<int> _requires;
    unordered_set<int> _isRequiredBy;
};
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        //loop through each course. 
        //if the outDegree is 0, take remove all edges going into it

        //if all complete, return true

        //if none are completed in a gothrough, return false because there is a cycle.  


        unordered_map<int, node> nodes;
        for(const auto & prereq : prerequisites){
            int dependent = prereq[0];
            int required = prereq[1];
            nodes[dependent]._requires.insert(required);
            nodes[required]._isRequiredBy.insert(dependent);
        }

        int completed = 0;
        while(true){
            bool allEmpty = true;
            bool allDependent = true;
            vector<int> toRemove;
            for(auto & p : nodes){
                int nodeNum = p.first;
                node& node = p.second;

                //if the node doesn't require any others, then all nodes requiring it don't require this one
                if(node._requires.size() == 0){
                    allDependent = false;
                    for(int dependentNum : node._isRequiredBy){
                        nodes[dependentNum]._requires.erase(nodeNum);
                    }
                    toRemove.push_back(nodeNum);
                } else {
                    allEmpty = false;
                }

            }

            for(const int i : toRemove){
                nodes.erase(i);
            }
            if(allEmpty || nodes.empty()){
                return true;
            }
            if(allDependent){
                return false;
            }
            

            
        }
        return true;

    }
};