class Solution {
public:
    unordered_map<int, int> map;
    int total;
    int m;
    int n;
    Solution(int m, int n) {
        total = m * n;
        this->n=n;
        this->m=m;
    }
    
    vector<int> flip() {
        int i = rand() % total;
        int resolvedI = get(i);
        int swapI = total - 1;
        total--;
        map[i] = get(swapI);
        //map.erase(total);

        return {resolvedI/n, resolvedI%n};

    }

    int get(int i) {
        if(map.contains(i)) {
            return map[i];
        }
        return i;
    }

    void reset() {
        map.clear();
        total = m * n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */