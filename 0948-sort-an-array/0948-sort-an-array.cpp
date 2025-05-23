class Solution {
private:
    //T is a random access iterator
    template <typename T>
    void mergesort(T begin, T end){
        
        if(next(begin) == end){
            return;
        }


        T back = prev(end);
        int n = end - begin;
        T m = begin + (end - begin) / 2;
        int mOffset = end - m;
        mergesort(begin, m);
        mergesort(m, end);

        //aggregate 
        T l = end - n;
        T lEnd = end - mOffset;
        T r = lEnd;
        T rEnd = end;

        //iterator_traits<T>::value_type returns the type that the given iterator points to. 
        using ValueType = iterator_traits<T>::value_type;
        vector<ValueType> merged(end - begin);
        
        T mergeItr = merged.begin();

        while(l != lEnd || r != rEnd) {
            if(l == lEnd){
                *mergeItr = *r;
                r = next(r);
            } else if(r == rEnd){
                *mergeItr = *l;
                l = next(l);
            } else if (*l < *r){
                *mergeItr = *l;
                l = next(l);
            } else {
                *mergeItr = *r;
                r = next(r);
            }
            mergeItr = next(mergeItr);
        }

        //update original array to match the merged array;
        T mergeBegin = merged.begin();
        T destBegin = end - n;

        while(mergeBegin != merged.end()){
            *destBegin = *mergeBegin;
            mergeBegin = next(mergeBegin);
            destBegin = next(destBegin);
        }

        
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums.begin(), nums.end());
        return nums;
    }
};