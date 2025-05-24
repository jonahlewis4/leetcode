class Solution {
private:
    template <typename T>
    void mergesort(T begin, T end) const {
        int n = end - begin;
        for(int size = 1; size < n; size *= 2){
            int sub1 = 0;
            int sub2 = sub1 + size;

            int sub1End = sub1 + size - 1;
            int sub2End = sub2 + size - 1;


            while(sub1 < n){
                if(sub1End >= n){
                    sub1End = n - 1;
                }
                if(sub2End >= n){
                    sub2End = n - 1;
                }
                int sub1Size = sub1End - sub1 + 1;
                int sub2Size = max(0, sub2End - sub2 + 1);
                
                auto firstElem = *begin;
                vector<decltype(firstElem)> merged(sub1Size + sub2Size);

                int mergeI = 0;
                int l = sub1;
                int r = sub2;
                while(l <= sub1End || r <= sub2End) {
                    if(l > sub1End){
                        merged[mergeI] = *(begin + r);
                        r++;
                    } else if (r > sub2End) {
                        merged[mergeI] = *(begin + l);
                        l++;
                    } else if (*(begin + l) < *(begin + r)){
                        merged[mergeI] = *(begin + l);
                        l++;
                    } else {
                        merged[mergeI] = *(begin + r);
                        r++;
                    }
                    mergeI++;
                }

                for(int i = 0; i < merged.size(); i++){
                    *(begin + sub1 + i) = merged[i];
                }

                sub1 += size * 2;
                sub2 += size * 2;
                sub1End += size * 2;
                sub2End += size * 2;
            }
        }
    }
public:
    template<typename T>
    vector<T> sortArray(vector<T>& nums) {
        mergesort(nums.begin(), nums.end());
        return nums;
    }
};