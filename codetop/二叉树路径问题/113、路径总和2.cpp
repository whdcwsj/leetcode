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

//记录根节点-叶子结点=target的路径总和
//路径问题，注意回溯
vector<vector<int>>res;
vector<int>path;

void dfs(TreeNode*node,int sum){
    if(!node) return;
    sum-=node->val;
    path.push_back(node->val);
    if(!node->left && !node->right && sum==0){
        res.push_back(path);
        return;
    }
    if(node->left){
        dfs(node->left,sum);
        //注意回溯
        path.pop_back();
    }
    if(node->right){
        dfs(node->right,sum);
        path.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    if(!root) return res;
    vector<int>path;
    dfs(root,targetSum);
    return res;
}