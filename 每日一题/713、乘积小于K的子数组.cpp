#include<bits/stdc++.h>
using namespace std;


//以下是非连续子数组的情况
// int res=0;
// vector<int>path;

// void backtracking(vector<int>& nums,int maxnum,int sum,int startIndex,vector<int>&path){
//     if(startIndex>=nums.size() || path.size()>=nums.size()) return;
//     for(int i=startIndex;i<nums.size();i++){
//         if(sum*nums[i]<maxnum){
//             res++;
//             path.push_back(nums[i]);
//             cout<<"res:"<<res<<endl;
//             for(int i=0;i<path.size();i++){
//                 cout<<path[i]<<" ";
//             }
//             cout<<endl;
//             backtracking(nums,maxnum,sum*nums[i],i+1,path);
//             path.pop_back();
//         }
//     }
// }


// int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//     backtracking(nums,k,1,0,path);
//     return res;
// }



//连续子数组，这样会超时
// int numSubarrayProductLessThanK(vector<int>& nums, int k){
//     int sum;
//     int count=0;
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         sum=1;
//         for(int j=i;j<n;j++){
//             sum*=nums[j];
//             if(sum<k){
//                 count++;
//             }
//             if(sum>=k){
//                 break;
//             }
//         }
//     }
//     return count;
// }


//滑动窗口
int numSubarrayProductLessThanK(vector<int>& nums, int k){
    if(k<=1) return 0;
    int n=nums.size();
    int left=0;
    int sum=1;
    int res=0;
    for(int i=0;i<n;i++){
        sum*=nums[i];
        while(sum>=k){
            sum/=nums[left++];
        }
        res+=i-left+1;
    }
    return res;
}


int main(){
    vector<int> nums = {10,5,2,6};
    int k=100;
    int ans=numSubarrayProductLessThanK(nums,k);
    cout<<ans<<endl;

    system("pause");
    return 0;
}