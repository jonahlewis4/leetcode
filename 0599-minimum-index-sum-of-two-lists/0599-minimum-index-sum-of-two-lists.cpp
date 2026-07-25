class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m2;
        for(int i = 0; i < list2.size(); i++) {
            string s = list2[i];
            m2[s] = i;
        }

        int curSum = INT_MAX;
        vector<string> res;
        for(int idx = 0; idx < list1.size(); idx++) {
            string& key = list1[idx];
            if(m2.contains(key)) {
                int sum = idx + m2[key];
                if(sum < curSum) {
                    curSum = sum;
                    res.clear();
                    res.push_back(key);
                } else if (sum == curSum) {
                    res.push_back(key);
                }
            }
        }

        return res;
    }
};