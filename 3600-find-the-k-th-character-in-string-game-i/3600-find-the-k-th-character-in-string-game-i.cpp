class Solution {
private:
    int log(int i) {
        return 31 - __builtin_clz(i);
    }
public:
    char kthCharacter(int k) {
        return get(k - 1);
    }
    
    char get(int k) {
        if(k == 0) {
            return 'a';
        }
        int logarithm = log(k);
        int segLength = 1 << logarithm;
        return get(k - segLength) + 1;
    }

};