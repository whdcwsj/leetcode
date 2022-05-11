#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*left,TreeNode*right):val(x),left(left),right(right){}
};


bool isMirrorTree(TreeNode*p,TreeNode*q){
    if(!p && !q) return true;
    else if(!p || !q) return false;
    else if(p->val!=q->val) return false;
    return isMirrorTree(p->left,q->right) && isMirrorTree(p->right,q->left);
}


//判断左右子树是否为相同的树
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isMirrorTree(root->left,root->right);
}