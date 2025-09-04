class Solution {
private:
    int _nums1FirstPos;
    int _nums2FirstPos;
    vector<int> _nums1;
    vector<int> _nums2;
    int _k;
    long long _smallestProd;
    long long _largestProd;

    void SetupSplit() {
        _nums1FirstPos = _nums1.size();
        for(int i = 0; i < _nums1.size(); i++) {
            if(_nums1[i] >= 0){
                _nums1FirstPos = i;
                break;
            }
        }
        _nums2FirstPos = _nums2.size();
        for(int i = 0; i < _nums2.size(); i++){
            if(_nums2[i] >= 0) {
                _nums2FirstPos = i;
                break;
            }
        }
    }

    void SetSearchBounds() {
        long long front1 = _nums1.front();
        long long front2 = _nums2.front();
        long long back1 = _nums1.back();
        long long back2 = _nums2.back();

        long long corner1 = front1 * front2;
        long long corner2 = front1 * back2;
        long long corner3 = front2 * back1;
        long long corner4 = back1 * back2;

        long long minProduct = min({
            corner1, corner2, corner3, corner4
        });
        long long maxProduct = max({
            corner1, corner2, corner3, corner4
        });
        _smallestProd = minProduct;
        _largestProd = maxProduct;
    }

    long long Rank(long long prod) const {
        long long rank = 0;
        //count values <= prod when both negative
        for(int i1 = 0, i2 = _nums2FirstPos - 1; i1 < _nums1FirstPos && i2 >= 0;){
            long long thisProduct = (long long)_nums1[i1] * _nums2[i2];
            if(thisProduct <= prod) {
                rank += _nums1FirstPos - i1;
                i2--;
            } else {
                i1++;
            }
        }
        
        //count values <= prod when both positive
        for(int i1 = _nums1FirstPos, i2 = _nums2.size() - 1; i1 < _nums1.size() && i2 >= _nums2FirstPos;){
            long long thisProduct = (long long)_nums1[i1] * _nums2[i2];
            if(thisProduct <= prod) {
                rank += i2 - _nums2FirstPos + 1;
                i1++;
            } else {
                i2--;
            }
        }

        //count values <= prod when num1 is positive and num2 is negative
        for(int i1 = _nums1.size() - 1, i2 = _nums2FirstPos - 1; i1 >= _nums1FirstPos && i2 >= 0;){
            long long thisProduct = (long long)_nums1[i1] * _nums2[i2];
            if(thisProduct <= prod) {
                rank += i2 + 1;
                i1--;
            } else {
                i2--;
            }
        }


        //count values <= prod when num1 is negative and num2 is positive
        for(int i1 = 0, i2 = _nums2FirstPos; i1 < _nums1FirstPos && i2 < _nums2.size();) {
            long long thisProduct = (long long)_nums1[i1] * _nums2[i2];
            if(thisProduct <= prod) {
                rank += _nums2.size() - i2;
                i1++;
            } else {
                i2++;
            }
        }
        
        return rank;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        _nums1 = nums1;
        _nums2 = nums2;
        _k = k;

        SetupSplit();
        SetSearchBounds();

        //Rank(-30);


        // for(const auto & num : nums1){
        //     for(const auto & num2 : nums2) {
        //         long long prod = (long long)num * num2;
        //         cout<<prod<<" is rank "<<Rank(prod)<<endl;
        //     }
        // }

        long long l = _smallestProd;
        long long r = _largestProd;
        while(l <= r) {
            long long m = (l + r) / 2;
            long long rank = Rank(m);

            if(rank < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }       

    

};