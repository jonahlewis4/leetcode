class Solution {
public:
    bool canChange(string start, string target) {
        std::queue<pair<char, int>> startQ;
        std::queue<pair<char, int>> targetQ;

        for(int i = 0; i < start.size(); i++){
            if(start[i] != '_'){
                startQ.push({start[i], i}) ;
            }
            if(target[i] != '_'){
                targetQ.push({target[i], i});
            }
        }


        if(targetQ.size() != startQ.size()){
            return false;
        }

        while(!targetQ.empty()){
            

            char targetC = targetQ.front().first;
            int targetIdx = targetQ.front().second;
            targetQ.pop();
            char startC = startQ.front().first;
            int startIdx = startQ.front().second;
            startQ.pop();

            
            if(targetC != startC){
                return false;
            }

            if(targetC == 'R' && startIdx > targetIdx){
                return false;
            }

            if(targetC == 'L' && startIdx < targetIdx){
                return false;
            }


        }

        return true;
    }
};