#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//判断是不是祖先节点，或者是不是p或者q
TreeNode* dfs(TreeNode*node, TreeNode*p, TreeNode*q){
    //终止条件
    if(!node) return NULL;
    if(node==p || node==q) return node;
    TreeNode*left=dfs(node->left,p,q);
    TreeNode*right=dfs(node->right,p,q);
    if(left && right){
        return node;
    }
    if(!left){
        return right;
    }
    if(!right){
        return left;
    }
    return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode*root, TreeNode*p, TreeNode*q){
    if(!root) return root;
    TreeNode*res=dfs(root,p,q);
    return res;
}
