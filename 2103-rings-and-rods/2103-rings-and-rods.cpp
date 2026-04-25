class Solution {
public:
    int countPoints(string rings) {
        array<unordered_set<char>, 10> arr;
        for(int i = 0; i < rings.size(); i+=2){
            char color = rings[i] ;
            int dest = rings[i + 1] - '0';
            arr[dest].insert(color);
        }

        int res = 0;
        for(const unordered_set<char>& set : arr) {
            if(set.size() == 3) {
                res++;
            }
        }
        return res;
    }
};