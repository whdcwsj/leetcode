#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*>q;
    if(root) q.push(root);
    vector<vector<int>>res;
    vector<int>wang;
    int flag=0;
    while(!q.empty()){
        int n=q.size();
        wang.clear();
        for(int i=0;i<n;i++){
            TreeNode*temp=q.front();
            q.pop();
            wang.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(flag%2==1){
            reverse(wang.begin(),wang.end());
        }
        res.push_back(wang);
        flag++;
    }
    return res;
}