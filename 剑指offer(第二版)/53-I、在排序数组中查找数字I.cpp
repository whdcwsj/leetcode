#include<bits/stdc++.h>
using namespace std;


//但是这样肯定，一定得二分，时间复杂度最优
// int search(vector<int>& nums, int target) {
//     int res=0;
//     for(auto&num:nums){
//         if(num==target) res++;
//     }
//     return res;
// }

//使用两次二分法，分别找到指定数字的左边界与右边界
// int search(vector<int>& nums, int target){
//    if(nums.size()==0) return 0;
//     auto pos1=lower_bound(nums.begin(),nums.end(),target);
//     auto pos2=upper_bound(nums.begin(),nums.end(),target)-1;
//     return pos2-pos1+1;
// }

int find_lower(vector<int>&nums,int target){
    int left=0;
    int right=nums.size();
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]<target) left=mid+1;
        else right=mid;
    }
    return right;
}

int find_upper(vector<int>&nums,int target){
    int left=0;
    int right=nums.size();
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]<=target) left=mid+1;
        else right=mid;
    }
    return right;
}

int search(vector<int>& nums, int target){
   if(nums.size()==0) return 0;
    auto pos1=find_lower(nums,target);
    auto pos2=find_upper(nums,target)-1;
    return pos2-pos1+1;
}


int main(){
    vector<int>nums = {5,7,7,8,8,10};
    int target = 8;
    int ans=search(nums,target);
    cout<<ans<<endl;

    system("pause");
    return 0;
}