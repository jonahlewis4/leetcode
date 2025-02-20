class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(const auto & point : points){
            if(pq.size() < k){
                pq.push({distance(point), point});
            } else {
                double dist = distance(point);
                if(dist < pq.top().first){
                    pq.pop();
                    pq.push({dist, point});
                }
            }
        }
        vector<vector<int>> ans(pq.size());
        for(int i = 0; i < ans.size(); i++){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
    double distance(const vector<int> & point){
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
};