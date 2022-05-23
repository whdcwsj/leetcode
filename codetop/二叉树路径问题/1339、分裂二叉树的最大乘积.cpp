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


// 后序遍历得到分别以各个节点为根的子树总和
// 去掉一条边的乘积=子树总和*（总和-子树总和）,取最大值
// 不能提前取模。比如1e9+7（取模后为0） 和 1e9 + 6（取模后不变），提前取模会导致错误

const int mod=1e9+7;
vector<long long>sums;

//得到以每个节点为根子树的和
long long dfs(TreeNode*node){
    if(!node) return 0;
    long long left=dfs(node->left);
    long long right=dfs(node->right);
    long long res=left+right+node->val;
    sums.push_back(res);
    return res;
}

int maxProduct(TreeNode* root) {
    if(!root) return 0;
    dfs(root);
    long long num=-1;
    for(int i=0;i<sums.size();i++){
        // 取最大值时不能取模，应该用long型存结果
        num=max(num,sums[i]*(sums.back()-sums[i]));
    }
    return (int)(num%mod);
}


int main(){
    int a=4,b=5,c=6;
    int ans=max({a,b,c});
    cout<<ans<<endl;

    system("pause");
    return 0;
}