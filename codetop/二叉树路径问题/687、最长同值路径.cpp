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

int res=0;
int dfs(TreeNode*node){
    if(!node) return 0;
    int left=dfs(node->left);
    int right=dfs(node->right);
    //左右节点是否与当前节点相同
    if(node->left && node->left->val==node->val){
        left++;
    }else{
        left=0;
    }
    if(node->right && node->right->val==node->val){
        right++;
    }else{
        right=0;
    }
    res=max(res,left+right);
    return max(left,right);
}

int longestUnivaluePath(TreeNode* root){
    if(!root) return 0;
    dfs(root);
    return res;
}