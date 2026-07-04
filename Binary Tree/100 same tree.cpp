/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //koi vi traversal kro dono me like pre,post,inodrer dono  me same ans ayega.
 //so isme ek sath dono me predorder krte h har node ko compare kar jayenge with traversal
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL || q==NULL){
            return p==q;
        }

        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};