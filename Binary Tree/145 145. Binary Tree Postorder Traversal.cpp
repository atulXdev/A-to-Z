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
class Solution {
public:
 void postorder(TreeNode* root,vector<int> & ans){
    if(root==NULL){
        return;
    }
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
 }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
        
    }
};

//POSTORDER TRAVERSAL USING TWO STACKS


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        stack<TreeNode*> st1,st2;
        vector<int> postorder;
        if(root==NULL) return postorder;
        st1.push(root);

        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root); //esme order ulta ayega right left root so again ek
            //loop chla ke ulta print kr denge and we will get left right root

            if(root->left!=NULL){
                st1.push(root->left);
            }

              if(root->right!=NULL){
                st1.push(root->right);
            }

        }

        while(!st2.empty()){
            root=st2.top();
            st2.pop();
            postorder.push_back(root->val);

        }
        return postorder;
    }
};

//ITETRATIVE POST ORDER TRAVERSAL USIN **1** STACK