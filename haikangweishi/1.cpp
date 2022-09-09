#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


//前序遍历
TreeNode* refanxulie(list<string>&dataArray){
    if(dataArray.front()=="#"){
        dataArray.erase(dataArray.begin());
        return NULL;
    }
    TreeNode*root=new TreeNode(stoi(dataArray.front()));
    dataArray.erase(dataArray.begin());
    root->left=refanxulie(dataArray);
    root->right=refanxulie(dataArray);
    return root;
}

TreeNode* fanxulie(string data){
    list<string>dataArray;
    stringstream ss;
    ss.str(data);
    string item;
    while(getline(ss,item,',')){
        dataArray.push_back(item);
    }
    return refanxulie(dataArray);
}

string res;

//前序
void rexulie(TreeNode*root){
    //终止条件
    if(root==NULL){
        res+="#,";
        return;
    }
    res+=to_string(root->val)+',';
    rexulie(root->left);
    rexulie(root->right);
}

string xulie(TreeNode*root){
    rexulie(root);
    return res;
}


int main(){
    string str;
    cin>>str;
    TreeNode*node=fanxulie(str);
    string ans=xulie(node);
    ans.pop_back();
    cout<<ans<<endl;

    system("pause");
    return 0;
}