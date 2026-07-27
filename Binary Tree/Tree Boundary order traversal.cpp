/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

//ques:https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
bool isLeaf(Node* node) {
        return node->left == nullptr && node->right == nullptr;
    }


void addLeftBoundary(Node* root,vector<int> & res){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else{
            curr=curr->right;
        }
    }
}

void addRightBoundary(Node* root,vector<int> & res){
    Node* curr=root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else{
            curr=curr->left;}
        
    }
    //storing in res array in opp order
    
    for(int i=temp.size()-1;i>=0;--i){
        res.push_back(temp[i]);
    }
}
//adding leaf nodes by preorder traversal
void addLeafs(Node* root,vector<int> & res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    
    if(root->left) addLeafs(root->left,res);
    if(root->right) addLeafs(root->right,res);
    
}
class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        //first take left boundary then leaf nodes(by preodrer) then right boundary in
        //reverse order except the leaf nodes as they are already taken
         vector<int> res;
         if(!root) return res;
         if(!isLeaf(root)) res.push_back(root->data);
         addLeftBoundary(root,res);
         addLeafs(root,res);
         addRightBoundary(root,res);
         
         return res;

        
    }
};