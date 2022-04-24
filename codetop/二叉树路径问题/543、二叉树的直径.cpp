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

//记录节点数目，边的个数-1就好
int res=0;
int dfs(TreeNode*node){
    if(!node) return 0;
    int left=dfs(node->left);
    int right=dfs(node->right);
    res=max(res,left+right+1);
    return max(left,right)+1;
}

int diameterOfBinaryTree(TreeNode* root){
    if(!root) return 0;
    dfs(root);
    return res-1;
}