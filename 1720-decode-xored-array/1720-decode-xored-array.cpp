class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size() + 1);
        res.front() = first;
        int prev = res.front();
        
        //1
        //1

        //1 0
        //0 1
        //0 0

        //0 0
        //1 0
        //1 0

        //1 0
        //1 1
        //0 1
        
        for(int i = 1; i < res.size(); i++) {
            res[i] = prev ^ encoded[i - 1];
            prev = res[i];
        }

        return res;
    }
};