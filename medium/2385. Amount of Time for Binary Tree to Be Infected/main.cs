/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int AmountOfTime(TreeNode root, int start) {
        Dictionary<TreeNode, TreeNode> parentMap = new Dictionary<TreeNode, TreeNode>();
        TreeNode startNode = FindStartNode(root, start, null, parentMap);
        if (startNode == null) return 0;

        Queue<TreeNode> queue = new Queue<TreeNode>();
        HashSet<TreeNode> visited = new HashSet<TreeNode>();
        queue.Enqueue(startNode);
        visited.Add(startNode);

        int minutes = 0;

        while (queue.Count > 0) {
            int levelSize = queue.Count; 

            for (int i = 0; i < levelSize; i++) {
                TreeNode currentNode = queue.Dequeue();

                // check the parents in the nodes
                TreeNode parentNode;
                if (parentMap.TryGetValue(currentNode, out parentNode) && parentNode != null && !visited.Contains(parentNode)) {
                    queue.Enqueue(parentNode);
                    visited.Add(parentNode);
                }

                // add infected children
                if (currentNode.left != null && !visited.Contains(currentNode.left)) {
                    queue.Enqueue(currentNode.left);
                    visited.Add(currentNode.left);
                }
                if (currentNode.right != null && !visited.Contains(currentNode.right)) {
                    queue.Enqueue(currentNode.right);
                    visited.Add(currentNode.right);
                }
            }

            if (queue.Count > 0) {
                minutes++;
            }
        }

        return minutes;
    }

    private TreeNode FindStartNode(TreeNode node, int start, TreeNode parent, Dictionary<TreeNode, TreeNode> parentMap) {
        if (node == null) {
            return null;
        }
        parentMap[node] = parent;  // memorize the parent node

        if (node.val == start) {
            return node;
        }

        TreeNode leftResult = FindStartNode(node.left, start, node, parentMap);
        if (leftResult != null) {
            return leftResult;
        }

        return FindStartNode(node.right, start, node, parentMap);
    }
}
