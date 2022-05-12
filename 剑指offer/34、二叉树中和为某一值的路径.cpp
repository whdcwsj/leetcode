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



vector<vector<int>>res;
vector<int>path;

void dfs(TreeNode* root,int sum){
    //终止条件
    if(!root) return;
    sum-=root->val;
    path.push_back(root->val);
    if(!root->left && !root->right && sum==0){
        res.push_back(path);
        return;
    }
    if(root->left){
        dfs(root->left,sum);
        path.pop_back();
    } 
    if(root->right){
        dfs(root->right,sum);
        path.pop_back();
    }
}


vector<vector<int>> pathSum(TreeNode* root, int target) {
    if(!root) return res;
    dfs(root,target);
    return res;
}