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

//返回按字典序最小的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。
//做一个sort就行
vector<string>res;

void dfs(TreeNode*node,string &s){
    if(!node) return;
    s+='a'+node->val;
    if(!node->left && !node->right){
        reverse(s.begin(),s.end());
        res.push_back(s);
        reverse(s.begin(),s.end());
        return;
    }
    if(node->left){
        dfs(node->left, s);
        s.pop_back();
    }
    if(node->right){
        dfs(node->right, s);
        s.pop_back();
    }
}

string smallestFromLeaf(TreeNode* root){
    if(!root) return s;
    dfs(root,s);
    sort(res.begin(),res.end());
    return res[0];
}