#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

//记录当前节点的前置节点
Node*pre=NULL;
//记录头结点
Node*head;

//二叉搜索树，中序遍历，从小到大
void dfs(Node*cur){
    if(!cur) return;
    dfs(cur->left);
    //无前置节点
    if(!pre){
        head=cur;
    }else{
        pre->right=cur;
    }
    cur->left=pre;
    pre=cur;
    dfs(cur->right);
}

Node* treeToDoublyList(Node* root) {
    if(!root) return root;
    dfs(root);
    //处理头尾节点相连
    pre->right=head;
    head->left=pre;
    return head;
}