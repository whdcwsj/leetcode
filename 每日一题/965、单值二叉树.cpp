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

int num;
bool isSame(TreeNode* root){
    if(!root) return true;
    if(root->val!=num) return false;
    return isSame(root->left) && isSame(root->right);
}


bool isUnivalTree(TreeNode* root) {
    num=root->val;
    return isSame(root);
}