class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0) {
            return vector<int>(code.size(), 0);
        }

        int sum = 0;
        vector<int> res(code.size(), 0);
        for(int i = 0; i < code.size() + abs(k); i++){
            int idx = i % code.size();
            int currentVal = code[idx];
            
            
            if(i >= abs(k)){
                int idxToUpdate = k > 0 ? (idx - k + code.size() - 1) % code.size()
                                        : idx;
                res[idxToUpdate] = sum;

                int poppedIdx = (i - abs(k) + code.size()) % code.size();
                sum -= code[poppedIdx];
            }

            sum += currentVal;
        }

        return res;
    }
};