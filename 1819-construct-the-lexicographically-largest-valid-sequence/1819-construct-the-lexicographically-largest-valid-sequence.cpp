class Solution {
private:
    vector<int> res = {};
    vector<bool> inSequence;
    int placed = 0;
    int n;
public:
    vector<int> constructDistancedSequence(int n) {
        // 5 as input :     0 1 2 3 4 5 6 7 8
        // lexic smallest : 1 2 2 3 3 4 4 5 5
        // lexic largest :  5         5
        //                  4       4

        this->n = n;
        inSequence.resize(n + 1, false);
        vector<int> sequence(n * 2 - 1, -1);
        calc(sequence, 0);
        return res;
    }   

    void calc(vector<int> &sequence, int nextOpen) {
        if(placed == inSequence.size() - 1){
            res = sequence;
            return;
        }
        
        for(int digit = n; digit >= 1; digit--){
            int nextOpen2 = nextOpen;
            if(inSequence[digit]){
                continue;
            }
            int pairIndex = nextOpen2 + digit;
            if(digit == 1){
                pairIndex = nextOpen2;
            }
            if(pairIndex >= sequence.size()){
                continue;
            }
            if(sequence[pairIndex] != -1){
                continue;
            }
    
            sequence[nextOpen] = digit;
            sequence[pairIndex] = digit;
            inSequence[digit] = true;
            nextOpen2++;
            while(nextOpen2 < sequence.size() && sequence[nextOpen2] != -1){
                nextOpen2++;
            }
            placed++;
            calc(sequence, nextOpen2);
            inSequence[digit] = false;
            sequence[nextOpen] = -1;
            sequence[pairIndex] = -1;
            placed--;
            if(!res.empty()){
                return;
            }
        }
        
    }


};