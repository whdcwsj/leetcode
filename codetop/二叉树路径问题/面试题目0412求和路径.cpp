#include<bits/stdc++.h>
using namespace std;

//从任意路径开始的，路径和满足要求的
//每个节点都要当一次根节点
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*left,TreeNode*right):val(x),left(left),right(right){}
};

int res;
void dfs(TreeNode*node,int target){
    if(!node) return;
    target-=node->val;
    if(target==0){
        res++;
    }
    dfs(node->left,target);
    dfs(node->right,target);
}
//从每个节点都要当做开头记录一次结果
int pathSum(TreeNode* root, int sum) {
    if(!root) return 0;
    dfs(root,sum);
    pathSum(root->left,sum);
    pathSum(root->right,sum);
    return res;
}