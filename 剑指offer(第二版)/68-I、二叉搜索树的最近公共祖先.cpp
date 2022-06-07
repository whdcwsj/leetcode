#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//如果是二叉树的话，就自底向上，分别递归返回左右子树p,q,或者NULL
//二叉搜索树的话，从上到下遍历就行
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root){
        if(p->val>root->val && q->val>root->val) root=root->right;
        else if(p->val<root->val && q->val<root->val) root=root->left;
        else return root;
    }
    return NULL;
}


//二叉树的写法
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