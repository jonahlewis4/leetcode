class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m1;
        for(int i = 0; i < list1.size(); i++) {
            string s = list1[i];
            m1[s] = i;
        }
        unordered_map<string, int> m2;
        for(int i = 0; i < list2.size(); i++) {
            string s = list2[i];
            m2[s] = i;
        }

        int curSum = INT_MAX;
        vector<string> res;
        for(const auto [key, idx] : m1) {
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