/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode merge(TreeNode a, TreeNode b) {
        if(a == null) {
            return b;
        }
        if(b == null) {
            return a;
        }

        TreeNode og = a;
        
        while(a.right != null) {
            a = a.right;
        }

        a.right = b;
        return og;
    }
    void deleteWithPar(TreeNode root, int key, TreeNode parent) {
        if(root == null) {
            return;
        }
        
        if(root.val == key) {
            if(root == parent.left) {
                parent.left = merge(root.left, root.right);
            } else {
                parent.right = merge(root.left, root.right);
            }
        }

        if(root.val > key) {
            deleteWithPar(root.left, key, root);
        } else {
            deleteWithPar(root.right, key, root);
        }
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) {
            return null;
        }
        
        if(root.val == key) {
            return merge(root.left, root.right);
        }

        if(root.val > key) {
            deleteWithPar(root.left, key, root);
        } else {
            deleteWithPar(root.right, key, root);
        }

        return root;
    }
}