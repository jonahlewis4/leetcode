class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        for(int i = 0; i + 1 < currentState.size(); i++){
            char first = currentState[i];
            char second = currentState[i + 1];

            if(first == '+' && second == '+'){
                currentState[i] = '-';
                currentState[i + 1] = '-';
                res.push_back(currentState);
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }            
        }

        return res;
    }
};