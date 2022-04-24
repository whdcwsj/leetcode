#include<bits/stdc++.h>
using namespace std;

//局部有序数组如何二分查找
//注意大小边界值的判断
int search(vector<int>& nums, int target) {
    int n=nums.size();
    if(n==1){
        return nums[0]==target?0:-1;
    }
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target) return mid;
        //判断有序数组的范围，左边有序数组
        if(nums[0]<=nums[mid]){
            if(nums[0]<=target && target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        //右边有序数组
        else{
            if(nums[mid]<target && target<=nums[n-1]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
    return -1;
}


int main(){
    vector<int>nums={4,5,6,7,0,1,2};
    int a=0;
    int res=search(nums,a);
    cout<<res<<endl;

    system("pause");
    return 0;
}