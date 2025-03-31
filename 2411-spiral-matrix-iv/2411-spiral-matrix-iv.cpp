/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

private: 

    struct dir{
        int r;
        int c;
    };

    vector<dir> dirs = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };



public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int visitCount = 0;
        int size = m * n;

        vector<vector<int>> res(m, vector<int>(n, -1));


        int r = 0;
        int c = 0;

        vector<int> walls(4);
        walls[0] = n; //right
        walls[1] = m; //bottom
        walls[2] = -1; //left
        walls[3] = -1; //top

        int dirIdx = 0;
        ListNode* cur = head;
        while(visitCount < size && cur != nullptr){
           
            
            
            res[r][c] = cur->val;
            auto [rOffset, cOffset] = dirs[(dirIdx + 4) % 4];
            int newR = r + rOffset;
            int newC = c + cOffset;
            visitCount++;
            if(visitCount >= size){
                break;
            }
            while( newC >= walls[0] || newR >= walls[1] || newC <= walls[2] || newR <= walls[3]){
                dirIdx++;
                auto [rOffset, cOffset] = dirs[(dirIdx + 4) % 4];
                newR = r + rOffset;
                newC = c + cOffset;
                int wallI = (dirIdx + 2) % 4;
                walls[wallI] += wallI < 2 ? -1 : 1;  //if first or second wall, sub 1. If third or fourth, add -1
            }
            r = newR;
            c = newC;
            cur = cur->next;
        }
        return res;


    }
};