class Solution {
public:
    void inorderTraversal(TreeNode* root, TreeNode*& prev, int& ans) {
        if (!root) return;

        inorderTraversal(root->left, prev, ans);
        if (prev) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        inorderTraversal(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        inorderTraversal(root, prev, ans);
        return ans;
    }
};
