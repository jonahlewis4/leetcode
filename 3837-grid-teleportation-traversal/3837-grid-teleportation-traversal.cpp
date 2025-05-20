class Solution {
private: 
    static vector<tuple<int, int>> dirs;
public:
    int minMoves(vector<string>& matrix) {
        struct point {
            int r; 
            int c;
        };
        struct teleportRing{
            bool explored = false;
            vector<point> points;
        };

        unordered_map<char, teleportRing> rings;
        vector<vector<bool>> enqueued(matrix.size(), vector<bool>(matrix[0].size(), false));

        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[r].size(); c++){
                char ch = matrix[r][c];
                if(ch == '#'){
                    enqueued[r][c] = true;
                }
                if(ch == '.' || ch == '#'){
                    continue;
                }
                
                rings[ch].points.push_back({
                    .r = r,
                    .c = c,
                });
            }
        }


        deque<point> dq;
        dq.push_back({
            .r = 0,
            .c = 0,
        });

        int moves = 0;

        while(!dq.empty()){
            int n = dq.size();
            for(int i = 0; i < n; i++){ 
                point p = dq.front();
                dq.pop_front();       

                int r = p.r;
                int c = p.c;
                
                if (r == matrix.size() - 1 && c == matrix[0].size() - 1) {
                    return moves;
                } 

                if(enqueued[r][c]) {
                    continue;
                }
                enqueued[r][c] = true;
                if(matrix[r][c] == '#'){
                    continue;
                }

                for(const auto & dir : dirs){
                    const auto [rOffset, cOffset] = dir;
                    int newR = r + rOffset;
                    int newC = c + cOffset;
                    if(newR < 0 || newC < 0 || newR >= matrix.size() || newC >= matrix[newR].size()){
                        continue;
                    }

                    if(enqueued[newR][newC]){
                        continue;
                    }
                    dq.push_back({
                        .r = newR,
                        .c = newC,
                    });
                }

                char ch = matrix[r][c];

                if(ch == '.' || ch == '#'){
                    continue;
                }

                auto &teleporter = rings[ch];
                if(teleporter.explored){
                    continue;
                }

                teleporter.explored = true;
                for(const auto & p : teleporter.points){
                    int newR = p.r;
                    int newC = p.c;
                    if(enqueued[newR][newC]){
                        continue;
                    }
                    dq.push_front({
                        .r = newR,
                        .c = newC,
                    });
                    n++;
                }

            }
            moves++;
        }

        return -1;
    }
};
vector<tuple<int, int>> Solution::dirs = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1},
};