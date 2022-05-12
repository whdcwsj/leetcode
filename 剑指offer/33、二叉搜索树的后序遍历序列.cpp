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


//最差的时间复杂度O(N2)
//1、注意二叉搜索树的性质，分治递归
bool travelsal(vector<int>& postorder,int left,int right){
    if(left>=right) return true;
    int index=left;
    //找分割点s
    while(postorder[index]<postorder[right]) index++;
    int mid=index;
    //验证右子区间
    while(postorder[index]>postorder[right]) index++;
    bool flag1=travelsal(postorder,left,mid-1);
    bool flag2=travelsal(postorder,mid,right-1);
    return flag1 && flag2 && index==right;
}


bool verifyPostorder(vector<int>& postorder) {
    return travelsal(postorder,0,postorder.size()-1);
}


//后续遍历的时候
//挨着的两个数如果arr[i]<arr[i+1]，那么arr[i+1]一定是arr[i]的右子节点
//如果arr[i]>arr[i+1]，那么arr[i+1]一定是arr[0]……arr[i]中某个节点的左子节点，并且这个值是大于arr[i+1]中最小的
//2、辅助栈，时间复杂度O(N)

//倒序入栈处理
//父节点值root=+∞ （初始值为正无穷大，可把树的根节点看为此无穷大节点的左孩子）


bool verifyPostorder(vector<int>& postorder) {
    stack<int>s;
    int parent=INT_MAX;
    for(int i=postorder.size()-1;i>=0;i--){
        int cur=postorder[i];
        //说明当前节点是之前某个节点的左节点
        while(!s.empty() && cur<s.top()){
            parent=s.top();
            s.pop();
        }
        if(cur>parent) return false;
        s.push(cur);
    }
    return true;
}