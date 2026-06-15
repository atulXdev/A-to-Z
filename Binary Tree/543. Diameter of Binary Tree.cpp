//Diameter:Longest path between two nodes
//path doesnot need to pass via root node
//extreme bruteforce:Har node ka left and right jake max height calculate and add it

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int currDiameter = leftHeight + rightHeight;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(currDiameter, max(leftDiameter, rightDiameter));
    }
};


//optimal

