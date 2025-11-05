class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    vector<int> factors;
    vector<int> factorsOf(int n) {
        vector<int> res;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                res.push_back(i);

                int comp = n / i;
                if(comp != i) {
                    res.push_back(comp);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
public:


    void r(int i, int t){
        if(t == 1){
            res.push_back(cur);
            return;
        }

        for(int j = i; j < factors.size(); j++) {
            int factor = factors[j];
        
            if(t % factor != 0){
                continue;
            }

            cur.push_back(factor);
            r(j, t / factor);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if(n == 1){
            return {};
        }

        factors = factorsOf(n);
        r(0, n);
        return res;
    }

    
};