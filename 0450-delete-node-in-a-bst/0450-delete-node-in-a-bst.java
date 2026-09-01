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
    TreeNode replace(TreeNode root) {
        if(root.left == null) {
            return root.right;
        } else if (root.right == null) {
            return root.left;
        }

        TreeNode pred = root.left;
        while(pred.right != null) {
            pred = pred.right;
        }
        root.val = pred.val;    
        root.left = deleteNode(root.left, root.val);
        return root;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) {
            return null;
        }

        if(root.val == key) {
            return replace(root);
        } 
        if(root.val > key) {
            root.left = deleteNode(root.left, key);
        } else {
            root.right = deleteNode(root.right, key);
        }

        return root;
    }
}