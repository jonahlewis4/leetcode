class Solution {
private:
    class SegmentTree{
    private:
        vector<int> seg;
        int n;
        void build(int segI, int l, int r, const vector<int> & arr) {
            if(l == r){
                seg[segI] = arr[l];
                return;
            }

            int m = (l + r) / 2;
            build(segI * 2 + 1, l, m, arr);
            build(segI * 2 + 2, m + 1, r, arr);

            seg[segI] = max(seg[segI * 2 + 1], seg[segI * 2 + 2]);
        }
        void update(int segI, int toUpdate, int l, int r, int newVal) {
            if(l == r){
                seg[segI] = newVal;
                return;
            }

            //determine which side to travel down.

            int m = (l + r) / 2;
            if(toUpdate <= m){
                update(segI * 2 + 1, toUpdate, l, m, newVal);
            } else {
                update(segI * 2 + 2, toUpdate, m + 1, r, newVal);
            }
            seg[segI] = max(seg[segI * 2 + 1], seg[segI * 2 + 2]);
        }

        int query(int segI, int qL, int qR, int l, int r) const {
            //if disjoint return
            if(r < qL || l > qR){
                return INT_MIN;
            }
            //if we're fully inside the query, return the value
            if(l >= qL && r <= qR){
                return seg[segI];
            }
            //otherwise reuturn max of right and left
            int m = (l + r) / 2;
            int left = query(segI * 2 + 1, qL, qR, l, m);
            int right = query(segI * 2 + 2, qL, qR, m + 1, r);
            return max(left, right);
        }

    public:
        SegmentTree(const vector<int> &arr) {
            n = arr.size();
            seg.resize(n * 4);

            build(0, 0, n - 1, arr);
        }
        void Update(int obstacleToUpdate, int newVal) {
            update(0, obstacleToUpdate, 0, n - 1, newVal);
            return;
        }
        int LargestWithin(int cutoff) {
            return query(0, 0, cutoff, 0, n - 1);
        }
    };
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        //segment tree stores the max distances between all obstacles
        //we can query from 0 to x and find distances for ALL obstacles before hand.
        //however, if x is not an obstacle we have an edge ase where we need to 
        //check its distance from the preceeding obstacle. 

        int maxObstacleDist = min(size_t(5e4), 3 * queries.size()) + 1;

        vector<int> flatObstacles(maxObstacleDist + 1, 0);
        flatObstacles[flatObstacles.size() - 1] = maxObstacleDist;
        SegmentTree tree(flatObstacles);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(maxObstacleDist);
        
        vector<bool> res;
        for(auto const & q : queries) {
            if(q[0] == 1){
                handleBlockInsert(q, obstacles, tree);
            } else {
                handleCheckFit(res, q, obstacles, tree);
            }
        }
        return res;
        
    }

    void handleBlockInsert(const vector<int> & q, set<int> &obstacles, SegmentTree &tree) {
        //get the obstacles before and after the current obstacle.

        int newObstacle = q[1];
        auto afterItr = obstacles.upper_bound(newObstacle);

        int next = *afterItr;
        int before = *(prev(afterItr));

        obstacles.insert(newObstacle);

        //update the distances to reflect this:
        //before to newObstacle is now the size of their difference
        //newObstacle to after is now the size of their differences
        tree.Update(newObstacle, newObstacle - before);
        tree.Update(next, next - newObstacle);
    }

    void handleCheckFit(vector<bool> & res, const vector<int> &q, set<int> &obstacles, SegmentTree &tree) {
        int sizeNeeded = q[2];
        int cutoff = q[1];

        //determine if any obstacles in the segment tree have one to their left that is equal or greater sizeNeeded.
        int largestDistBetweenObstacles = tree.LargestWithin(cutoff);

        if(largestDistBetweenObstacles >= sizeNeeded){
            res.push_back(true);
            return;
        }

        //edge case: the tree only tracks the distances between obstacles 
        //if the cutoff is not an obstacle, our query will return the largest all the way up to the final obstacle
        // before the cutoff.
        //If the distance from THAT obstacle to the cutoff is >= size, it is also valid.

        auto afterItr = obstacles.lower_bound(cutoff);
        auto before = *(prev(afterItr));

        int alternateSize = cutoff - before;

        if(alternateSize >= sizeNeeded){
            res.push_back(true);
            return;
        }
        
        res.push_back(false);

    }
};