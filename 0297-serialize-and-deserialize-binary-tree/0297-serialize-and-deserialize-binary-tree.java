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
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(q.size() > 0) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode front = q.poll();
                if(front == null) {
                    sb.append("N,");
                    continue;
                }
                sb.append(""+front.val+",");
                q.add(front.left);
                q.add(front.right);
            }
        }
        
        while(sb.length() >= 2 && sb.charAt(sb.length() - 2) == 'N'){
            sb.setLength(sb.length() - 2);
        }
        if(sb.length() > 0) {
            sb.setLength(sb.length() - 1);
        }
        return sb.toString();
    }

    class Parser {
        String s;
        int i = 0;
        Parser(String data) {
            s=data;
        }
        boolean atEnd() {
            return i >=  s.length();
        }
        TreeNode getNext() {
            if(s.charAt(i) == 'N') {
                i+=2;
                return null;
            }
            int amount = 0;
            boolean negative = false;
            while(i < s.length() && s.charAt(i) != ','){
                char c = s.charAt(i);
                i++;
                if(c == '-') {
                    negative = true;
                    continue;
                }
                amount *= 10;
                amount += c - '0';
            }
            i++;
            if(negative) {
                amount = -amount;
            }
            return new TreeNode(amount);
        }
    };
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Parser p = new Parser(data);
        if(p.atEnd()) {
            return null;
        }

        TreeNode root = p.getNext();


        Queue<TreeNode> q= new ArrayDeque<>();
        q.add(root);
        while(q.size() > 0) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode front = q.poll();
                if(!p.atEnd()) {
                    front.left = p.getNext();
                }
                if(!p.atEnd()) {
                    front.right = p.getNext();
                }

                if(front.left != null) {
                    q.add(front.left);
                }
                if(front.right != null) {
                    q.add(front.right);
                }
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