class Solution {
public:
    bool canChange(string start, string target) {
        int startIdx = 0;
        int targetIdx = 0;

        while(startIdx < start.size() || targetIdx < target.size()){
            while(startIdx < start.size() && start[startIdx] == '_'){
                startIdx++;
            }
            while(targetIdx < target.size() && target[targetIdx] == '_'){
                targetIdx++;
            }


            if(startIdx == start.size() && targetIdx != target.size()){
                return false;
            }
            if(targetIdx == start.size() && startIdx != target.size()){
                return false;
            }
            
            if(startIdx == start.size() && targetIdx == target.size()){
                return true;
            }

            if(target[targetIdx] != start[startIdx]
                || (start[startIdx] == 'L' && targetIdx > startIdx)
                || (start[startIdx] == 'R' && targetIdx < startIdx)
            ){
                return false;
            }
            targetIdx++;
            startIdx++;
        }

        return true;
    }
};