/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function(root) {
    let maxDiff = 0;

    const dfs = (node, minAncestor, maxAncestor) => {
        if (!node) return;

        // Update the maxDiff using the current node's value
        maxDiff = Math.max(maxDiff, Math.abs(node.val - minAncestor), Math.abs(node.val - maxAncestor));

        // Update the min and max ancestor values
        minAncestor = Math.min(minAncestor, node.val);
        maxAncestor = Math.max(maxAncestor, node.val);

        // Continue DFS on left and right children
        dfs(node.left, minAncestor, maxAncestor);
        dfs(node.right, minAncestor, maxAncestor);
    };

    dfs(root, root.val, root.val);
    return maxDiff;
};
