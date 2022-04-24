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

//是否存在路径等于target
bool flag=false;
void dfs(TreeNode*node,int sum){
    if(!node) return;
    sum-=node->val;
    if(sum==0 && !node->left && !node->right){
        flag=true;
        return;
    }
    dfs(node->left,sum);
    dfs(node->right,sum);
} 

bool hasPathSum(TreeNode* root, int targetSum){
    if(!root) return false;
    dfs(root,targetSum);
    return flag;
}