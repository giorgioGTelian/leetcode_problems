#include <queue>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        std::unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = findStartNode(root, start, nullptr, parentMap);
        if (startNode == nullptr) return 0;

        std::queue<TreeNode*> queue;
        std::unordered_set<TreeNode*> visited;
        queue.push(startNode);
        visited.insert(startNode);

        int minutes = 0;

        while (!queue.empty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = queue.front();
                queue.pop();

                // Controlla e aggiungi il nodo genitore
                auto it = parentMap.find(currentNode);
                if (it != parentMap.end() && visited.find(it->second) == visited.end() && it->second != nullptr) {
                    queue.push(it->second);
                    visited.insert(it->second);
                }

                // Aggiungi i figli non infetti
                if (currentNode->left && visited.find(currentNode->left) == visited.end()) {
                    queue.push(currentNode->left);
                    visited.insert(currentNode->left);
                }
                if (currentNode->right && visited.find(currentNode->right) == visited.end()) {
                    queue.push(currentNode->right);
                    visited.insert(currentNode->right);
                }
            }

            if (!queue.empty()) {
                minutes++;
            }
        }

        return minutes;
    }

private:
    TreeNode* findStartNode(TreeNode* node, int start, TreeNode* parent, std::unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (node == nullptr) return nullptr;
        parentMap[node] = parent;

        if (node->val == start) return node;
        
        TreeNode* leftResult = findStartNode(node->left, start, node, parentMap);
        if (leftResult != nullptr) return leftResult;
        
        return findStartNode(node->right, start, node, parentMap);
    }
};
