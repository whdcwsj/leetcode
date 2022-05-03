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

//前序+中序
//递归做法
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0) return NULL;
    int cur_value=preorder[0];
    TreeNode*node=new TreeNode(cur_value);
    //只剩一个叶子结点
    if(preorder.size()==1) return node;

    int in_index;
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==cur_value){
            in_index=i;
            break;
        }
    }

    //vector之间赋值，左闭右开
    vector<int>left_inorder(inorder.begin(),inorder.begin()+in_index);
    vector<int>right_inorder(inorder.begin()+in_index+1,inorder.end());
    vector<int>left_preorder(preorder.begin()+1,preorder.begin()+1+left_inorder.size());
    vector<int>right_preorder(preorder.begin()+1+left_inorder.size(),preorder.end());

    node->left=buildTree(left_preorder,left_inorder);
    node->right=buildTree(right_preorder,right_inorder);
    return node;
}


//迭代做法
//用栈
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){

}