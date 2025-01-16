class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxTillNow = -1;
        int chunks = 0;
        for(int i = 0; i < arr.size(); i++){
            maxTillNow = max(maxTillNow, arr[i]);
            if(maxTillNow == i){
                chunks++;
                maxTillNow = -1;
            }
        }
        return chunks;
    }
};