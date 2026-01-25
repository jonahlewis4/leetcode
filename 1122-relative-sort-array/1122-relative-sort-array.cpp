class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count;
        for(const int i : arr1) {
            count[i]++;
        }

        vector<int> res(arr1.size(), 0);
        int j = 0;
        for(int i = 0; i < arr2.size(); i++) {
            int val = arr2[i];
            int c = count[val];
            for(int k = 0; k < c; k++) {
                res[j] = val;
                j++;
            }
            count.erase(val);
        }

        int sortStart = j;
        while(!count.empty()) {
            const auto& [val, c] = *count.begin();
            for(int k = 0; k < c; k++) {
                res[j] = val;
                j++;
            }
            count.erase(val);
        }

        sort(res.begin() + sortStart, res.end());

        return res;
    }
};