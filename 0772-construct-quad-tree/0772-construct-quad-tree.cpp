/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    class Range {
        const vector<vector<int>>& grid;
        int r1;
        int r2;
        int c1;
        int c2;
    public:
        Range(const vector<vector<int>>& grid, int r1, int r2, int c1, int c2) : grid(grid){
            this->r1 = r1;
            this->r2 = r2;
            this->c1 = c1;
            this->c2 = c2;
        }

        bool isUniform() const {
            vector<int> count(2);
            for(int r = r1; r <= r2; r++) {
                for(int c = c1; c <= c2; c++) {
                    count[grid[r][c]]++;
                }
            }

            int height = r2 - r1 + 1;
            int width = c2 - c1 + 1;
            int area = height * width;

            return count.front() == area || count.back() == area;
        }

        bool val() const {
            return grid[r1][c1];
        }
    };

    Node* build(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        Range range(grid, r1, r2, c1, c2);
        
        Node* res = new Node();

        if(range.isUniform()){
            res->val = range.val();
            res->isLeaf = true;
        } else {
            res->isLeaf = false;
            
            int rm = r1 + (r2 - r1)/2;
            int cm = c1 + (c2 - c1)/2;
            res->topLeft = build(grid, r1, rm, c1, cm);
            res->topRight = build(grid, r1, rm, cm + 1, c2);
            res->bottomLeft = build(grid, rm + 1, r2, c1, cm);
            res->bottomRight = build(grid, rm + 1, r2, cm + 1, c2);
        }

        return res;
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, grid.size() - 1, 0, grid.front().size() - 1);
    }
};