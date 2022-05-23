#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


string s;

void reserialize(TreeNode* root) {
    if(!root){
        s+="None,";
        return;
    }
    s+=to_string(root->val)+',';
    reserialize(root->left);
    reserialize(root->right);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    reserialize(root);
    return s;
}


TreeNode*redeserialize(list<string>&temp){
    if(temp.front()=="None"){
        temp.erase(temp.begin());
        return NULL;
    }
    TreeNode*node=new TreeNode(stoi(temp.front()));
    temp.erase(temp.begin());
    node->left=redeserialize(temp);
    node->right=redeserialize(temp);
    return node;
}


// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    list<string>temp;
    stringstream ss(data);
    string item;
    while(getline(ss,item,',')){
        temp.push_back(item);
    }
    return redeserialize(temp);
}