class Solution {
public:
    int candy(vector<int>& ratings) {
        struct child {
            int indegree = 0;
            vector<int> outgoing;
            int candies = 1;
        };

        vector<child> children(ratings.size());
        for(int i = 0; i < ratings.size(); i++){
            //outgoing are the ones which are larger
            if(i - 1 >= 0 && ratings[i - 1] > ratings[i]) {
                children[i].outgoing.push_back(i - 1);
                children[i - 1].indegree++;
            }

            if(i + 1 < ratings.size() && ratings[i + 1] > ratings[i]){
                children[i].outgoing.push_back(i + 1);
                children[i + 1].indegree++;
            }
        }

        queue<int> q;
        for(int i = 0; i < children.size(); i++){
            if(children[i].indegree == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(const auto & neigh : children[i].outgoing) {
                children[neigh].candies = max(children[neigh].candies, children[i].candies + 1);
                children[neigh].indegree--;
                if(children[neigh].indegree == 0){
                    q.push(neigh);
                }
            }
        }

        int totalCandies = 0;
        for(const auto & child : children) {
            totalCandies += child.candies;
        }

        return totalCandies;
    }
};