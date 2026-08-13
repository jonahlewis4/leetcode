class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        for(int r = 0; r < matrix.size(); r++) {
            pq.push({matrix[r][0], r, 0});
        }
    
        for(int i = 1; i < k; i++) {
            auto [val, row, col] = pq.top();
            pq.pop();
            if(col + 1 < matrix.size()) {
                pq.push({matrix[row][col + 1], row, col + 1});
            }
        }

        tuple<int, int, int> res = pq.top();
        return get<0>(res);

        
    }
};