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

//可以swap的
TreeNode* mirrorTree(TreeNode* root) {
    if(!root) return NULL;
    TreeNode*left=mirrorTree(root->right);
    TreeNode*right=mirrorTree(root->left);
    root->left=left;
    root->right=right;
    return root;
}