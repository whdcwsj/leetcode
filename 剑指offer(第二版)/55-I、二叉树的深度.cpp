#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int dfs(TreeNode*root){
    if(!root) return 0;
    int left_num=dfs(root->left);
    int right_num=dfs(root->right);
    return max(left_num,right_num)+1;
}


int maxDepth(TreeNode* root) {
    int res=dfs(root);
    return res;
}