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
        string res = "";
        serializeDfs(root, res);
        if(res.size() > 0 && res.back() == ','){
            res.pop_back();
        }
        return res;
    }
    void serializeDfs(TreeNode* root, string &res){
        if(root == nullptr){
            res += "null,";
            return;
        }
        res += to_string(root->val);
        res += ',';
        serializeDfs(root->left, res);
        serializeDfs(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto nodes = split(data, ',');
        
        if(nodes.size() == 0 || nodes[0] == "null"){
            return nullptr;
        }
        int i = 0;
        TreeNode* head = deserialize(nodes, i);
        return head;

    }

    TreeNode* deserialize(vector<string> & nodes, int & i){
        if(i >= nodes.size() || nodes[i] == "null"){
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        root->left = deserialize(nodes, i);
        root->right = deserialize(nodes, i);
        return root;
        
    }

    vector<string> split(string data, char delim){
        vector<string> res;
        int l = 0;
        int r = 0;
        string newStr = "";
        while(r < data.size()){
            if(data[r] == delim && newStr != ""){
                res.push_back(newStr);
                l = r + 1;
                newStr = "";
            } else {
                newStr += data[r];
            }
            r++;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));