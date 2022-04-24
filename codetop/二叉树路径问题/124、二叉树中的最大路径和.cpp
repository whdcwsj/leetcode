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

/*
非自顶向下的二叉树路径问题
设计辅助函数maxpath，调用自身以当前节点为根节点的左侧最长路径Lef和右侧最长路径right，
经过该节点的最长路径为left+right
从当前节点不断开始dfs就行,不断比较更新全局变量
*/
int res=0;

//因为要调用，返回值设置为int
int maxPath(TreeNode*root){
    if(!root) return 0;
    int left=maxPath(root->left);
    int right=maxPath(root->right);
    res=max(res,left+right+root->val);
    return max(left,right);
}


int res=INT_MIN;
int dfs(TreeNode*node){
    if(!node) return 0;
    //注意，可能小于0，负数不需要参与贡献度
    int left=max(dfs(node->left),0);
    int right=max(dfs(node->right),0);
    res=max(res,left+right+node->val);
    return max(left,right)+node->val;
}

int maxPathSum(TreeNode* root) {
    if(!root) return 0;
    dfs(root);
    return res;
}