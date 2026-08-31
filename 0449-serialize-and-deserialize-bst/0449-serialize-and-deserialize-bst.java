/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public static void s(TreeNode root, StringBuilder sb) {
        if(root == null) {
            return;
        }
        sb.append("" + root.val + ",");
        s(root.left, sb);
        s(root.right, sb);
    }
    public String serialize(TreeNode root) {
        if(root == null) {
            return "";
        }

        StringBuilder sb = new StringBuilder();

        s(root, sb);
        sb.setLength(sb.length() - 1);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        class Parser{
            String s;
            int i = 0;
            Parser(String data) {
                s=data;
            }

            boolean atEnd() {
                return i >= s.length();
            }
            TreeNode getNext() {
                int total = 0;
                while(i < s.length() && s.charAt(i) != ',') {
                    char c = s.charAt(i);
                    total *= 10;
                    total += c - '0';
                    i++;
                }
                i++;
                return new TreeNode(total);
            }
        }
        Deque<TreeNode> s = new ArrayDeque<TreeNode>();
        
        Parser p = new Parser(data);
        if(p.atEnd()) {
            return null;
        }
        TreeNode root = p.getNext();
        TreeNode cur = root;
        while(!p.atEnd()) {
            TreeNode next = p.getNext();
            if(cur.val > next.val) {
                cur.left = next;
                s.push(cur);
                cur = next;
            } else {
                while(s.size() > 0 && s.peek().val < next.val){
                   cur = s.pop();
                }
                cur.right = next;
                s.push(next);
                cur = next;
            }

        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;