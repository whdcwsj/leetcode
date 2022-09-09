#include<bits/stdc++.h>
using namespace std;

//左边界，找第一个大于等于target的下标，也就是第一个不小于
int getLeftBorder(vector<int>&nums, int target){
    int left=0;
    int right=nums.size();
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]<target)  left=mid+1;
        else{
            right=mid;
        }      
    }
    return right;
}

//右边界，找第一个大于target的下标，再减一
int getRightBorder(vector<int>&nums, int target){
    int left=0;
    int right=nums.size();
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]<=target) left=mid+1;
        else{
            right=mid;
        }
    }
    return right-1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int leftBorder = getLeftBorder(nums, target);
    int rightBorder = getRightBorder(nums, target);
    if(leftBorder<=rightBorder && nums[rightBorder]==target && nums[leftBorder]==target) return vector<int>{leftBorder,rightBorder};
    else return vector<int>{-1,-1};
}

int main(){
    vector<int>nums = {5,7,7,8,8,10};
    int target = 6;
    vector<int>res = searchRange(nums,target);
    for(auto&a:res){
        cout<<a<<" "<<endl;
    }
    cout<<endl;

    system("pause");
    return 0;
}