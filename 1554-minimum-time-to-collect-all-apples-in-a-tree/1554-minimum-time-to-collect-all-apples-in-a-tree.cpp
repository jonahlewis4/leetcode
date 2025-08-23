class Solution {
    class TreeNode {
        public:
            vector<int> children;
            bool hasApple = false;
    };
    vector<TreeNode> _nodes;
    vector<bool> _visited;
    vector<TreeNode> getTree(int n, const vector<vector<int>>& edges, const vector<bool>& hasApple) {
        vector<TreeNode> nodes(n);
        for(const auto & edge : edges) {
            int a = edge[0];
            int b = edge[1];
            nodes[a].children.push_back(b);
            nodes[b].children.push_back(a);
        }
        for(int i = 0; i < hasApple.size(); i++) {
            nodes[i].hasApple = hasApple[i];
        }
        return nodes;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<TreeNode> nodes = getTree(n, edges, hasApple);
        _nodes = nodes;
        _visited.resize(_nodes.size(), false);
        TreeNode* zeroNode = &_nodes[0];
        int df = dfs(0);
        if(df == 0) {
            return 0;
        }
        return (df - 1) * 2;
    }
    int dfs(int rootI) {
        if(_visited[rootI]) {
            return 0;
        }
        _visited[rootI] = true;
        TreeNode* root = &_nodes[rootI];

        int total = 0;
        for(const int childI : root->children) {
            total += dfs(childI);
        }

        if(total == 0 && root->hasApple) {
            return 1;
        }
        if(total == 0 && !root->hasApple) {
            return 0;
        }
        return total + 1;
    }


};