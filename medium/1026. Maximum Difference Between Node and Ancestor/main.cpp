struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;

        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int minAncestor, int maxAncestor) {
            if (!node) return;

            maxDiff = max(maxDiff, abs(node->val - minAncestor));
            maxDiff = max(maxDiff, abs(node->val - maxAncestor));

            minAncestor = min(minAncestor, node->val);
            maxAncestor = max(maxAncestor, node->val);

            dfs(node->left, minAncestor, maxAncestor);
            dfs(node->right, minAncestor, maxAncestor);
        };

        dfs(root, root->val, root->val);
        return maxDiff;
    }
};
