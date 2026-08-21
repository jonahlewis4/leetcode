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
    private int r(TreeNode root, ArrayList<Long> sums, int targetSum) {
        if(root == null) {
            return 0;
        }

        int total = 0;
        if(root.val == targetSum) {
            total++;
        }

        for(int i = 0; i < sums.size(); i++) {
            if(sums.get(i) + root.val == targetSum) {
                total++;
            }
            sums.set(i, sums.get(i) + root.val);
        }

        sums.add((long)root.val);
        total += r(root.left, sums, targetSum);
        total += r(root.right, sums, targetSum);
        for(int i = 0; i < sums.size(); i++) {
            sums.set(i, sums.get(i) - root.val);
        }
        sums.remove(sums.size() - 1);
        return total;

    }
    public int pathSum(TreeNode root, int targetSum) {
        ArrayList<Long> sums = new ArrayList();
        return r(root, sums, targetSum);

    }
}