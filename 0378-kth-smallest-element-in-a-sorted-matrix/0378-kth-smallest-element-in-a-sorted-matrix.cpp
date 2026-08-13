class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(const vector<int>& row : matrix) {
            for(const int val : row) {
                pq.push(val);
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};