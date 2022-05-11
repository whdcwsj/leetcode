#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/yi-pian-wen-zhang-jie-jue-suo-you-er-cha-kcb0/
*/

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*left,TreeNode*right):val(x),left(left),right(right){}
};

//自顶而下：以DFS为主
//1、一般路径
vector<int>res;
void dfs(TreeNode*root,vector<int>&path){
    //终止条件：空节点直接返回
    if(!root) return;
    path.push_back(root->val);
    //叶子结点
    if(!root->left && !root->right){
        res.push_back(path);
        return;
    }
    dfs(root->left,path);
    dfs(root->right,path);
}

//2、给定和的路径
void dfs(TreeNode*root,int sum,vector<int>&path){
    //终止条件
    if(!root) return;
    sum-=root->val;
    path.push_back(root->val);
    if(!root->left && !root->right && sum==0){
        res.push_back(path);
        return;
    }
    dfs(root->left,sum,path);
    dfs(root->right,sum,path);
}

//3、注意点
/*
1、如果找路径的和等于target，不需要新增变量，不断用target减去节点的数值就行
1.1、回溯路径的时候，要额外判断左右节点是否存在，存在再dfs()
2、是否要回溯？（基本上不用回溯）
3、找到路径后是否要return？取决于题目是否要求找到叶节点满足条件的路径,如果必须到叶节点,那么就要return;
但如果是到任意节点都可以，那么必不能return，因为还要在此基础上继续递归
4、是否要双重递归？(即调用根节点的dfs函数后，继续调用根左右节点的pathsum函数)
看题目要不要求从根节点开始的，还是从任意节点开始
*/

vector<string>res;
void dfs(TreeNode*node,string path){
    //终止条件
    if(!node) return;
    //string中的push_back只能是char类型的字符
    path+=to_string(node->val);
    if(!node->left && !node->right){
        res.push_back(path);
        return;
    }
    //这种path+"->"可以避免回溯
    if(node->left) dfs(node->left,path+"->");
    if(node->right) dfs(node->right,path+"->");
}

vector<string> binaryTreePaths(TreeNode* root){
    string path;
    if(!root) return res;
    dfs(root,path);
    return res;
}