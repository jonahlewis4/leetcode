class Solution {
    static int factorial(int n) {
        int res = 1;
        for(int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
    static string search(int before, int subProblemSize, vector<bool>& used, int k) {
        
        int unusedNumbers = 0;
        for(const bool wasUsed : used) {
            if(!wasUsed){
                unusedNumbers++;
            }
        }


        if(unusedNumbers == 1) {
            int res = 0;
            for(int i = 0; i < used.size(); i++) {
                if(!used[i]) {
                    return to_string(i + 1);
                }
            }
        }

        int remaining = k - before;
        int subproblemsToSkip = (remaining-1) / subProblemSize;
        

        int pickedSubProblem = 0;
        int skipped = -1;
        for(int i = 0; i < used.size(); i++) {
            if(skipped == subproblemsToSkip) {
                break;
            }

            if(!used[i]) {
                skipped++;
                pickedSubProblem = i + 1;
            }
        }

        used[pickedSubProblem-1] = true;
        unusedNumbers--;
        return to_string(pickedSubProblem) + search(before + subproblemsToSkip * subProblemSize, subProblemSize/unusedNumbers, used, k);
    }
public:
    string getPermutation(int n, int k) {
        vector<bool> used(n, false);
        int totalPermutations = factorial(n);
        int subProblemSize = totalPermutations / n;

        return search(0, subProblemSize, used, k);

    }
};