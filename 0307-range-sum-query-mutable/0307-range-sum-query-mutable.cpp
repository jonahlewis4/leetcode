class NumArray {
private:
    class SegmentTree {
    private:
        struct Node {
            int sum = 0;
            int left = -1;
            int right = -1;
            //int lazy = 0;

            Node(){};
        };

        void build(int i, int l, int r, const vector<int> & nums){
            auto & n = nodes[i];
            n.left = l;
            n.right = r;
            if(l == r){
                n.sum = nums[l]; 
            } else {
                int m = (l + r) / 2;
                build(i * 2 + 1, l, m, nums);
                build(i * 2 + 2, m + 1, r, nums);
                n.sum = nodes[i * 2 + 1].sum + nodes[i * 2 + 2].sum;
            }
        }

        int query(int i, int l, int r){
            auto &n = nodes[i];
            if(l <= n.left && r >= n.right){
                return n.sum;
            } else if (l > n.right || r < n.left) {
                return 0;
            } else {
                int lSum = query(i * 2 + 1, l, r);
                int rSum = query(i * 2 + 2, l, r);
                return lSum + rSum;
            }
        }
        void update(int i, int changed, int newVal){
            auto &n = nodes[i];
            if(n.left == changed && n.right == changed){
                n.sum = newVal;
            } else if (changed > n.right || changed < n.left){
                return;
            } else {
                update(i * 2 + 1, changed, newVal);
                update(i * 2 + 2, changed, newVal);
                n.sum = nodes[i * 2 + 1].sum + nodes[i * 2 + 2].sum;
            }
        }


        vector<Node> nodes;
        int n;


    public:
        SegmentTree(const vector<int> &nums){
            n = nums.size();
            nodes.resize(n * 4);
            build(0, 0, n -1, nums);
        }
        int Query(int l, int r){
            return query(0, l, r);
        }
        void Update(int i, int newVal){
            update(0, i, newVal);
        }
        void Update(int l, int r, int delta){
            return;
        }

    };

    SegmentTree *tree;
public:
    NumArray(vector<int>& nums) {
        auto theTree = new SegmentTree(nums);
        tree = theTree;
    }
    
    void update(int index, int val) {
        tree->Update(index, val);    
    }
    
    int sumRange(int left, int right) {
        return tree->Query(left, right);
    }

    ~NumArray() {
        delete tree;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */