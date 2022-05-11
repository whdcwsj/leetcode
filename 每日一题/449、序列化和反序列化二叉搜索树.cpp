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

//保存中间结果
string str;

void reserialize(TreeNode* root){
    if(root==NULL){
        str+="None,";
        return;
    }
    str+=to_string(root->val)+',';
    reserialize(root->left);
    reserialize(root->right);
}


// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    reserialize(root);
    return str;
}

TreeNode* redeserialize(list<string>&dataArray){
    if(dataArray.front()=="None"){
        dataArray.erase(dataArray.begin());
        return NULL;
    }
    TreeNode*root =new TreeNode(stoi(dataArray.front()));
    dataArray.erase(dataArray.begin());
    root->left=redeserialize(dataArray);
    root->right=redeserialize(dataArray);
    return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    list<string>dataArray;
    stringstream ss(data);
    string temp;
    while(getline(ss,temp,',')){
        dataArray.push_back(temp);
    }
    return redeserialize(dataArray);
}