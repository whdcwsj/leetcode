#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    //上一层
    TreeNode*next;
    TreeNode():val(0),left(NULL),right(NULL),next(NULL){}
    TreeNode(int x):val(x),left(NULL),right(NULL),next{NULL}{}
    TreeNode(int x,TreeNode*left,TreeNode*right,TreeNode*next):val(x),left(left),right(right),next(next){}
};

TreeNode* zhongxu_next(TreeNode*node){
    //特殊情况
    if(node==NULL) return NULL;
    //右子树有无
    if(node->right!=NULL){
        node=node->right;
        while(node->left!=NULL){
            node=node->left;
        }
        return node;
    }else{
        //向上找
        while(node->next!=NULL){
            //左左左
            if(node->next->left==node){
                return node->next;
            }
            node=node->next;
        }
        return NULL;
    }
}