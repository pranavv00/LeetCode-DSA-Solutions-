class Solution {
public:
    int maxD = 0;
    unordered_map<int, int> ump;

    TreeNode* LCA(TreeNode* root) {
        if (root == NULL || ump[root->val] == maxD)
            return root;

        TreeNode* leftN = LCA(root->left);
        TreeNode* rightN = LCA(root->right);

        if (leftN != NULL && rightN != NULL)
            return root;

        return leftN ? leftN : rightN;
    }

    void depthOfNodes(TreeNode* root, int currD) {
        if (root) {
            maxD = max(maxD, currD);
            ump[root->val] = currD;
            depthOfNodes(root->left, currD + 1);
            depthOfNodes(root->right, currD + 1);
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depthOfNodes(root, 0);
        return LCA(root);
    }
};