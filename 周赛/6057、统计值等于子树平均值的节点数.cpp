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

int num=0;

//返回子节点的个数，sum
vector<int> getNum(TreeNode*node){
    if(node==NULL) return {0,0};
    vector<int> leftCount=getNum(node->left);
    vector<int> rightCount=getNum(node->right);
    int sum=leftCount[1]+rightCount[1]+node->val;
    int nodeNum=leftCount[0]+rightCount[0]+1;
    if(floor(sum/nodeNum)==node->val){
        num++;
    }
    return {nodeNum,sum};
}


int averageOfSubtree(TreeNode* root) {
    vector<int>temp=getNum(root);
    return num;
}