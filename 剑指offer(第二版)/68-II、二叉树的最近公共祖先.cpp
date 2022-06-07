#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //终止条件
    if(root==p || root==q || root==NULL) return root;
    TreeNode*left=lowestCommonAncestor(root->left,p,q);
    TreeNode*right=lowestCommonAncestor(root->right,p,q);
    if(left!=NULL && right!=NULL){
        return root;
    }
    else if(left==NULL && right!=NULL){
        return right;
    }
    else if(left!=NULL && right==NULL){
        return left;
    }
    else{
        return NULL;
    } 
}