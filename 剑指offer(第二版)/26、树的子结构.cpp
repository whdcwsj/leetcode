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

//是否为相同子树s
bool isSameTree(TreeNode* p, TreeNode* q){
    //均为空
    if(!p && !q) return true;
    //这道题比较中允许q已经NULL了，但是P后续还有节点
    if(!q) return true;
    if(!p || !q  || p->val!=q->val) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

bool isSubTree(TreeNode* a, TreeNode* b){
    if(!a) return false;
    if(isSameTree(a,b)) return true;
    return isSubStructure(a->left,b) || isSubStructure(a->right,b);
}


bool isSubStructure(TreeNode* a, TreeNode* b) {
    //排除初始的b为空节点
    if(!b) return false;
    return isSubTree(a,b);
}