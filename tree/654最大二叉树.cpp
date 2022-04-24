#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* travalsal(vector<int>& nums,int left,int right){
        TreeNode* newroot=new TreeNode(0);
        // 循环终止条件
        if(left>=right) return nullptr;
        if(right-left==1){
            newroot->val=nums[left];
            return newroot;
        }
        // 分割点
        int maxValue=INT_MIN;
        int maxIndex=INT_MIN;
        for(int i=left;i<nums.size();i++){
            if(nums[i]>maxValue){
                maxValue=nums[i];
                maxIndex=i;
            }
        }
        newroot->val=maxValue;
        // 左闭右开
        newroot->left=travalsal(nums,left,maxIndex);
        newroot->right=travalsal(nums,maxIndex+1,right);
        return newroot;
    }

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return travalsal(nums,0,nums.size());
    }

int main()
{
    vector<int>input={3,2,1,6,0,5};
    TreeNode* root;
    root=constructMaximumBinaryTree(input);
    printf(root->val);
    system("pause");
    return 0;
}
