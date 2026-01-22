class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        const vector<int>& e1 = edges.front();
        const vector<int>& e2 = edges.back();

        if(e1.front() == e2.front()) {
            return e1.front();
        }
        if(e1.front() == e2.back()) {
            return e1.front();
        }
        if(e1.back() == e2.back()) {
            return e1.back();
        }

        if(e1.back() == e2.front()){
            return e1.back();
        }

        return 0;
    }
};