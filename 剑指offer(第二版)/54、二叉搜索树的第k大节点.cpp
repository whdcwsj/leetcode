#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res;
int temp;
void dfs(TreeNode*root){
    if(!root) return;
    dfs(root->right);
    //当前的处理
    temp--;
    if(temp==0) res=root->val;
    dfs(root->left);
}


int kthLargest(TreeNode* root, int k) {
    temp=k;
    dfs(root);
    return res;
}