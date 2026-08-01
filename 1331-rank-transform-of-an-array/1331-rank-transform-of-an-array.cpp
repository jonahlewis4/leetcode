class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> set;
        unordered_map<int, vector<int>> is;
        for(const int i : arr) {
            set.insert(i);
        }
        for(int i = 0; i < arr.size(); i++) {
            is[arr[i]].push_back(i);
        }

        vector<int> res(arr.size());
        int j = 1;
        for(const int i : set) {
            for(const int idx : is[i]) {
                res[idx] = j;
            }
            j++;
        }
        return res;
    }
};