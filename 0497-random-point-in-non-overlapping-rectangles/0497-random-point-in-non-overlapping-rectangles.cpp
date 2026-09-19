class Solution {
    vector<int> prefixArea;
    vector<vector<int>>& rects;
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        prefixArea.resize(rects.size());
        for(int i = 0; i < rects.size(); i++) {
            const vector<int>& rect = rects[i];
            int a = rect.front();
            int b = rect[1];
            int x = rect[2];
            int y = rect.back();

            int xDelta = x - a;
            int yDelta = y - b;
            int area = (xDelta + 1) * (yDelta + 1);
            prefixArea[i] = area;
            if(i > 0) {
                prefixArea[i] += prefixArea[i-1];
            }
        }
    }
    
    vector<int> pick() {
        int target = rand() % prefixArea.back() + 1;
        //get index of first one bigger
        vector<int>::iterator itr = lower_bound(prefixArea.begin(), prefixArea.end(), target);
        int rectIdx = itr - prefixArea.begin();

        return randPoint(rects[rectIdx]);
    }

    vector<int> randPoint(vector<int>& rect) {
        int a = rect.front();
        int b = rect[1];
        int x = rect[2];
        int y = rect.back();

        int xDelta = x - a;
        int yDelta = y - b;

        int xOffset = rand() % (xDelta + 1);
        int yOffset = rand() % (yDelta + 1);
        return {a + xOffset, b + yOffset};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */