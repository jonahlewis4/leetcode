class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> choices;
        int subProblemSize = 1;
        for(int i = 1; i <= n; i++) {
            choices.push_back(i);
            subProblemSize *= i;
        }

        subProblemSize /= n;

        string res = "";
        for(int i = 1; i <= n; i++) {
            if(k == 0) {
                break;
            }
            cout<<i<<endl;
            int bucket = (k-1) / subProblemSize;
            res.push_back(choices[bucket] + '0');
            choices.erase(choices.begin() + bucket);

            k %= subProblemSize;
            if(k == 0) {
                k += subProblemSize;
            }

            if(subProblemSize > 1) {
                subProblemSize /= (n-i); 
            }

        }

        return res;
    }
};