class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> suspicious(n, false);
        suspicious[k] = true;
        queue<int> q;
        q.push(k);
        
        
        vector<vector<int>> adjList(n);
        for(const vector<int>& invo : invocations) {
            adjList[invo.front()].push_back(invo.back());
        }
        
        while(!q.empty()) {
            int m = q.size();
            for(int i = 0; i < m; i++) {
                int method = q.front();
                q.pop();

                for(const int invoked : adjList[method]) {
                    if(!suspicious[invoked]) {
                        q.push(invoked);
                        suspicious[invoked] = true;
                    }
                }
            }
        }

        bool mustKeep = false;
        for(int i = 0; i < n; i++) {
            if(suspicious[i]) {
                continue;
            }
            for(const int invocation : adjList[i]) {
                if(suspicious[invocation]) {
                    mustKeep = true;
                    break; 
                }
            }
        }

        if(mustKeep) {
            vector<int> res(n);
            iota(res.begin(), res.end(), 0);
            return res;
        } else {
            vector<int> res;
            for(int i = 0; i < n; i++) {
                if(!suspicious[i]) {
                    res.push_back(i);
                }
            }
            return res;
        }
    }
};