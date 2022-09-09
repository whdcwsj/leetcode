#include<bits/stdc++.h>
using namespace std;


// int search(vector<int>& nums, int target) {
//     int left=0;
//     int right=nums.size();
//     while(left<right){
//         int mid = left+(right-left)/2;
//         if(nums[mid]==target) return mid;
//         else if(nums[mid]<target) left=mid+1;
//         else right=mid;
//     }
//     return -1;
// }

// 使用lower_bound()解决
// 注意处理lower_bound找不到的问题
int search(vector<int>& nums, int target) {
    auto it=lower_bound(nums.begin(),nums.end(),target);
    if(it!=nums.end()  && *it==target) return it-nums.begin();
    else return -1;
}





int main(){
    // vector<int>nums = {-1,0,3,5,9,12};
    // int target = 9;
    vector<int>nums = {-1};
    int target = 2;
    int res = search(nums,target);
    cout<<res<<endl;

    system("pause");
    return 0;
}