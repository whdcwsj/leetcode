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
    int leftHeight=dfs(root->left);
    int rightHeight=dfs(root->right);
    if(leftHeight==-1) return -1;
    if(rightHeight==-1) return -1;
    if(abs(leftHeight-rightHeight)>1) return-1;
    else return max(leftHeight,rightHeight)+1;
}


bool isBalanced(TreeNode* root) {
    int res=dfs(root);
    return res==-1?false:true; 
}