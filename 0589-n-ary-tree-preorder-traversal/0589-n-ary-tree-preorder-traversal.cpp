class Solution {
public:
    vector<int> preorder(Node* root) {
        
        if(!root){
            return {};
        }
        stack<Node*> stk;
        stk.push(root);

        vector<int> res;
        while(!stk.empty()){
            Node* top = stk.top();
            stk.pop();
            res.push_back(top->val);
            for(auto itr = top->children.rbegin(); itr != top->children.rend(); itr++) {
                stk.push(*itr);
            }
        }
        return res;
    }
};