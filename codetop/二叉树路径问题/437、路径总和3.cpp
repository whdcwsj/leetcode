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

// 找节点数值=target的数值，找路径数量
// 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）

int res;
void dfs(TreeNode*node,long long sum){
    if(!node) return;
    sum-=node->val;
    if(sum==0){
        res++;
    }
    dfs(node->left,sum);
    dfs(node->right,sum);
}

int pathSum(TreeNode* root, int targetSum){
    if(!root) return 0;
    dfs(root,(long long)targetSum);
    pathSum(root->left,targetSum);
    pathSum(root->right,targetSum);
    return res;
}