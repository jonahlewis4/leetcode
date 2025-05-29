class Solution {
private:
    vector<int> res;
    struct valIPair{
        int val;
        int ogIndex;
    };
    vector<valIPair> valI;

    void mergeSort(int l, int r) {
        for(int size = 1; size <= r - l + 1; size *= 2){
            int start1 = l;
            int start2 = l + size;

            int end1 = start2 - 1;
            int end2 = end1 + size;
            
            while(start1 <= r){
                
                if(end2 > r){
                    end2 = r;
                }
                if(start2 > r){
                    end2 = r;
                    start2 = r + 1;
                }
                if(end1 > r){
                    end1 = r;
                }
                merge(start1, end1, start2, end2);

                start1 += size * 2;
                start2 += size * 2;
                end1 += size * 2;
                end2 += size * 2;
            }
        }
    }

    void merge(int start1, int end1, int start2, int end2) {
        auto _res = &res;
        auto _valI = &valI;
        int oldStart1 = start1;
        int oldStart2 = start2;
        vector<valIPair> merged(end2 - start1 + 1);
        int mergeI = 0;

        while(start1 <= end1 || start2 <= end2) {
            if(start1 > end1){
                merged[mergeI] = valI[start2];
                start2++;
            } else if (start2 > end2){
                res[valI[start1].ogIndex] += start2 - oldStart2;
                merged[mergeI] = valI[start1];
                start1++;
            } else if (valI[start1].val <= valI[start2].val){
                res[valI[start1].ogIndex] += start2 - oldStart2;
                merged[mergeI] = valI[start1];
                start1++;
            } else {
                merged[mergeI] = valI[start2];
                start2++;
                
            }

            mergeI++;
        }

        for(int i = oldStart1; i <= end2; i++){
            valI[i] = merged[i - oldStart1];
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        valI.resize(nums.size());
        for(int i = 0; i < nums.size(); i++){
            valI[i] = {
                .val = nums[i],
                .ogIndex = i,
            };
        }

        res.resize(nums.size(), 0);
        
        mergeSort(0, nums.size() - 1);
        return res;
    }
};