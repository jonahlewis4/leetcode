class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> q;
        for(int i = 0; i < dominoes.size(); i++) {
            char c = dominoes[i];
            if(c != '.') {
                q.push(i);
            }
        }

        while(!q.empty()){ 
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int idx = q.front();
                q.pop();
                
                char c = dominoes[idx];
                if(c == 'L') {
                    if(idx - 1 < 0 || dominoes[idx - 1] != '.') {
                        continue;
                    }
                    dominoes[idx - 1] = 'L';
                    q.push(idx - 1);
                } else {
                    if(idx + 1 >= dominoes.size() || dominoes[idx + 1] != '.') {
                        continue;
                    }
                    if(idx + 2 < dominoes.size() && dominoes[idx + 2] == 'L') {
                        q.pop();
                        i++;
                        continue;
                    }
                    dominoes[idx + 1] = 'R';
                    q.push(idx + 1);\
                }
            }
        }
        return dominoes;
    }
};