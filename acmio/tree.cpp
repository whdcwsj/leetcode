#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//ACM模式二叉树的输入与输出
//树节点的构造
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode():val(-1),left(nullptr),right(nullptr){};
    TreeNode(int n):val(n),left(nullptr),right(nullptr){};
    TreeNode(int n,TreeNode*left,TreeNode*right):val(n),left(left),right(right){};
};


// 根据数组构造二叉树
TreeNode* constructTree(vector<int>&nums){
    TreeNode *root=NULL;
    int n=nums.size();
    if(n==0) return root;
    vector<TreeNode*>res(n,NULL);
    for(int i=0;i<n;i++){
        TreeNode*node=NULL;
        if(nums[i]!=-1) node=new TreeNode(nums[i]);
        //-1当做空节点
        res[i]=node;
        //记录根节点
        if(i==0) root=node;
    }
    for(int i=0;i*2+2<res.size();i++){
        //非空节点
        if(res[i]!=NULL){
            res[i]->left=res[i*2+1];
            res[i]->right=res[i*2+2];
        }
    }
    return root;
}


// 层序打印打印二叉树
void printTree(TreeNode* root) {
    queue<TreeNode*>q;
    if (root != NULL) q.push(root);
    vector<int>res;
    while(!q.empty()) {
        int size=q.size();
        for (int i=0;i<size;i++) {
            TreeNode* node=q.front();
            q.pop();
            if(node!=NULL) {
                res.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            // 这里的处理逻辑是为了把null节点打印出来，用-1 表示null
            else res.push_back(-1);
        }
    }
    for (int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }
}

int main(){

    // 注意本代码没有考虑输入异常数据的情况
    // 用 -1 来表示null
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = constructTree(vec);
    printTree(root);

    system("pause");
    return 0;
}