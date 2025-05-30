class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int p1;
        int p2;
        vector<bool> visit1(edges.size(), false);
        vector<bool> visit2(edges.size(), false);
        p1 = node1;
        p2 = node2;
        while(p1 != -1 || p2 != -1){
            if(p1 != -1){
                int top = p1;
                //might not need this check
                if(visit1[top]){
                    p1 = -1;
                    continue;
                }
                if(visit2[top]){
                    if(p2 != -1){
                        int top2 = p2;
                        if(visit1[top2]){
                            if(top2 < top){
                                return top2;
                            }
                        }
                    }
                    return top;
                }
                visit1[top] = true;
                p1 = edges[top];
            }


            if(p2 != -1){
                int top = p2;

                if(visit2[top]){
                    p2 = -1;
                    continue;
                }
                if(visit1[top]){
                    return top;
                }
                visit2[top] = true;
                p2 = edges[top];
            }
        }
        return -1;
    }
};