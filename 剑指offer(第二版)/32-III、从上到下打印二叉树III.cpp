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


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>res;
    if(!root) return res;
    queue<TreeNode*>q;
    q.push(root);
    int flag=1;
    while(!q.empty()){
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
            auto t=q.front();
            q.pop();
            level.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(flag%2==0){
            reverse(level.begin(),level.end());
        }
        flag++;
        res.push_back(level);
    }
    return res;
}