class Solution {

private:
    struct hashFunction 
    {    
        size_t operator()(const vector<int> & x) const
        { 
            return x[0] ^ x[1]; 
        } 
    };
public:
    int minAreaRect(vector<vector<int>>& points) {
        std::unordered_set<vector<int>, hashFunction> set;
        for(const auto & point : points){
            set.insert(point);
        }

        int minArea = INT_MAX;
        for(int i = 0; i < points.size() - 1; i++){
            for(int j = i + 1; j < points.size(); j++){
                int xD = points[j][0] - points[i][0];
                int yD = points[j][1] - points[i][1];
                
                if(xD == 0 || yD == 0){
                    continue;
                }

                vector<int> p2 = {points[i][0] + xD, points[i][1]};
                vector<int> p4 = {points[i][0], points[i][1] + yD};

                if(set.find(p2) != set.end() && set.find(p4) != set.end()){
                    minArea = min(minArea, abs(xD * yD));
                }
            }
        }

        return minArea == INT_MAX ? 0 : minArea;
    }
};