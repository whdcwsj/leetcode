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

//这样时间与空间利用程度太低
// vector<int> res;
// void dfs(TreeNode*root){
//     if(root==NULL) return;
//     res.push_back(root->val);
//     dfs(root->left);
//     dfs(root->right);
// }

// vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
//     dfs(root1);
//     dfs(root2);
//     sort(res.begin(),res.end());
//     return res;
// }


//☆好的解法：中序遍历直接获取有序的数组
//归并排序，合并两个有序的数组

vector<int>res;
vector<int>nums1,nums2;

void dfs(TreeNode*root, vector<int>&num){
    if(root==NULL) return;
    dfs(root->left,num);
    num.push_back(root->val);
    dfs(root->right,num);
}


vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
    dfs(root1,nums1);
    dfs(root2,nums2);
    int m=nums1.size();
    int n=nums2.size();
    res.resize(m+n);
    int i=0,j=0;
    int k=0;
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            res[k++]=nums1[i++];
        }else{
            res[k++]=nums2[j++];
        }
    }
    while(i<m){
        res[k++]=nums1[i++];
    }
    while(j<n){
        res[k++]=nums2[j++];
    }
    return res;
}