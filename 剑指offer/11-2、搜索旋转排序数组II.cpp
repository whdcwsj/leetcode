#include <bits/stdc++.h>
using namespace std;



bool search(vector<int>& nums, int target) {
    int n=nums.size();
    if(n==1){
        if(nums.front()==target){
            return true;
        }else{
            return false;
        }
    }
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target) return true;
        //右边有序数组
        if(nums[mid]<nums[right]){
            if(target>=nums[mid] && target<=nums[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        //左边有序数组
        else if(nums[mid]>nums[right]){
            if(target>=nums[left] && target<=nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        //有重复数值
        else{
            right--;
        }
    }
    return false;
}





int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    int target=0;
    bool ans=search(nums,target);
    cout<<ans<<endl;

    system("pause");
    return 0;
}