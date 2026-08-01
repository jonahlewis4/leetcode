class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;

        int r = 1;
        for(const int i : temp) {
            if(!rank.contains(i)) {
                rank[i] = r;
                r++;
            }
        }

        vector<int> res(arr.size());
        for(int i = 0; i < arr.size(); i++){
            res[i] = rank[arr[i]];
        }

        return res;
        
    }
};