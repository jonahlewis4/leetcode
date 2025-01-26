/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "null";
        }
        string res = "";
        std::stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* cur = stack.top();
            stack.pop();
            if(cur == nullptr){
                res += "null";
            } else {
                res += to_string(cur->val);
                stack.push(cur->right);
                stack.push(cur->left);
            }
            res += ",";
        }
        if(!res.empty() && res.back() == ','){
            res.pop_back();
        }
        return res;
        
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "null"){
            return nullptr;
        }
        vector<string> nodes = split(data, ',');
        int i = 0;
        stack<pair<TreeNode*, bool>> stack;
        TreeNode* root = ston(nodes[i]);
        i++;
        stack.push({root, true});
        stack.push({root, false});

        while(!stack.empty()){
            auto [parent, isRightChild] = stack.top();
            stack.pop();

            TreeNode* child = ston(nodes[i]);
            i++;
            if(isRightChild){
                parent->right = child;
            } else {
                parent->left = child;
            }

            if(child != nullptr){
                stack.push({child, true});
                stack.push({child, false});
            }
        }

        return root;
    }
    TreeNode* ston(string s){
        if(s == "null"){
            return nullptr;
        }
        return new TreeNode(stoi(s));
    }

    vector<string> split(string s, char delim){
         int l = 0; 
         int r = 0;
         vector<string> res;
         while(r < s.size() + 1){
            if(s[r] == delim || r == s.size()) {
                string sub = s.substr(l, r - l);
                if(sub != ""){
                  res.push_back(sub);
                }
                l = r + 1;
            }
            r++;
         }
         return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));