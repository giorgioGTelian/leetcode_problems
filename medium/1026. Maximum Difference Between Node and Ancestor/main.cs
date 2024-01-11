public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public int MaxAncestorDiff(TreeNode root) {
        int maxDiff = 0;

        void Dfs(TreeNode node, int minAncestor, int maxAncestor) {
            if (node == null) return;

            maxDiff = Math.Max(maxDiff, Math.Abs(node.val - minAncestor));
            maxDiff = Math.Max(maxDiff, Math.Abs(node.val - maxAncestor));

            minAncestor = Math.Min(minAncestor, node.val);
            maxAncestor = Math.Max(maxAncestor, node.val);

            Dfs(node.left, minAncestor, maxAncestor);
            Dfs(node.right, minAncestor, maxAncestor);
        }

        Dfs(root, root.val, root.val);
        return maxDiff;
    }
}
