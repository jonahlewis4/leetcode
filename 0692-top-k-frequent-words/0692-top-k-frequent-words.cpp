class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for(const string& word : words) {
            count[word]++;
        }

        auto cmp = [&count](const string& a, const string& b){
            int aCount = count[a];
            int bCount = count[b];

            if(aCount > bCount) {
                return true;
            }
            if(bCount > aCount) {
                return false;
            }

            return a < b;
        };

        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

        for(const auto &[key, c] : count) {
            pq.push(key);
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> res(pq.size());
        for(int i = 0; i < res.size(); i++) {
            res[res.size() - i - 1] = pq.top();
            pq.pop();
        }

        return res;
    }
};