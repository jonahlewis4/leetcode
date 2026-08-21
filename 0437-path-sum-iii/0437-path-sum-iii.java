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
    public int r(TreeNode root, Map<Long, Integer> sums, long sum, int targetSum) {
        if(root == null) {
            return 0;
        }

        int total = 0;
        sum += (long)root.val;
        total += sums.getOrDefault(sum - targetSum, 0);
        sums.put(sum, sums.getOrDefault(sum, 0) + 1);
        total += r(root.left, sums, sum, targetSum);
        total += r(root.right, sums, sum, targetSum);
        sums.put(sum, sums.get(sum) - 1);
        return total;
    }
    public int pathSum(TreeNode root, int targetSum) {
        Map<Long, Integer> sums = new HashMap<>();
        sums.put(0l, 1);
        return r(root, sums, 0, targetSum);
    }
}