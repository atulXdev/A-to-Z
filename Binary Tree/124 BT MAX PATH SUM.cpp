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


 //path:between two nodes you have to take all nodes appearing that is your path
 //if we do bruteforce we have to analyze all paths, if nodes are n we will take n^2
 //if at a node we have left sum of all node and right sum of all nodes then path sum is: node val +(left part sum+right part sum) final ans: val+(max left sum+max right sum)
 //here we use height and width conecpt of BT

class Solution {
public:
int maxPathDown(TreeNode* node,int &maxi){
    if(node==NULL) return 0;

//if you get left/right path anytime a negative number then dont take that path
//it will  ot give you max sum instead of take it as 0(not considering that path)
    int left=max(0,maxPathDown(node->left,maxi));
    int right=max(0,maxPathDown(node->right,maxi));
    maxi=max(maxi,left+right+node->val);
    return max(left,right) + node->val;
}
    int maxPathSum(TreeNode* root) {

        int maxi=INT_MIN;
        maxPathDown(root,maxi);

        return maxi;
        
    }
};