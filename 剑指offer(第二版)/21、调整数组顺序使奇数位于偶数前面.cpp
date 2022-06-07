#include<bits/stdc++.h>
using namespace std;

//首尾双指针
vector<int> exchange(vector<int>& nums) {
    if(nums.size()==0) return nums;
    int n=nums.size();
    int j=n-1;
    int i=0;
    while(i<j){
        //找第一个偶数
        while(i<j && nums[i]%2==1){
            i++;
        }
        //找第一个指数
        while(i<j && nums[j]%2==0){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    return nums;
}


//快慢双指针
//快指针找到奇数，就与慢指针交换位置
vector<int> exchange(vector<int>& nums){
    if(nums.size()==0) return nums;
    int n=nums.size();
    int fast=0;
    int low=0;
    while(fast<n){
        if(nums[fast]%2==1){
            swap(nums[low],nums[fast]);
            low++;
        }
        fast++;
    }
    return nums;
}


int main(){
    vector<int> nums = {1,2,3,4};
    vector<int>ans=exchange(nums);
    for(auto & a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}