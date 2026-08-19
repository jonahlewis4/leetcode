class Solution {
    static int diff(const string& a, const string& b) {
        int total = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                total++;
            }
        }
        return total;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);

        int mutations = 0;
        unordered_set<string> used;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                string s = q.front();
                q.pop();

                if(s == endGene) {
                    return mutations;
                }

                for(const string& mutCandidate : bank) {
                    if(diff(s, mutCandidate) == 1 && !used.contains(mutCandidate)){
                        used.insert(mutCandidate);
                        q.push(mutCandidate);
                    } 
                }
            }
            mutations++;
        } 


        return -1;
    }
};