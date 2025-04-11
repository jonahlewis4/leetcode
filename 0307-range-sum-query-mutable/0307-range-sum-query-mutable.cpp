class NumArray {
private:
    class SegmentTree {
    private:
        struct Node {
            int sum = 0;
            // int left = -1;
            // int right = -1;
            //int lazy = 0;

            Node(){};
        };

        void build(int i, int l, int r, const vector<int> & nums){
            auto & n = nodes[i];
            // n.left = l;
            // n.right = r;
            if(l == r){
                n.sum = nums[l]; 
            } else {
                int m = (l + r) / 2;
                build(i * 2 + 1, l, m, nums);
                build(i * 2 + 2, m + 1, r, nums);
                n.sum = nodes[i * 2 + 1].sum + nodes[i * 2 + 2].sum;
            }
        }

        int query(int i, int l, int r, int ll, int lr){
            auto &n = nodes[i];
            if(l <= ll && r >= lr){
                return n.sum;
            } else if (l > lr || r < ll) {
                return 0;
            } else {
                int m = (ll + lr) / 2;
                int lSum = query(i * 2 + 1, l, r, ll, m);
                int rSum = query(i * 2 + 2, l, r, m + 1, lr);
                return lSum + rSum;
            }
        }
        void update(int i, int changed, int newVal, int ll, int lr){
            auto &n = nodes[i];
            if(ll == changed && lr == changed){
                n.sum = newVal;
            } else if (changed > lr || changed < ll){
                return;
            } else {
                int m = (ll + lr) / 2;
                update(i * 2 + 1, changed, newVal, ll, m);
                update(i * 2 + 2, changed, newVal, m + 1, lr);
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
            return query(0, l, r, 0, n - 1);
        }
        void Update(int i, int newVal){
            update(0, i, newVal, 0, n - 1);
        }
        void Update(int l, int r, int delta){
            return;
        }

    };

    SegmentTree tree;
public:
    NumArray(vector<int>& nums) : tree(nums) {    }
    
    void update(int index, int val) {
        tree.Update(index, val);    
    }
    
    int sumRange(int left, int right) {
        return tree.Query(left, right);
    }

    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */