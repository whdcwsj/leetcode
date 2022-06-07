#include <bits/stdc++.h>
using namespace std;


//时间复杂度O(log n)，空间复杂度O(1)
int search(vector<int>& nums, int target){
    if(nums.size()==1){
        if(target==nums[0]){
            return 0;
        }else{
            return -1;
        }
    }
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target) return mid;
        //右边有序数组
        if(nums[mid]<=nums[right]){
            if(target>= nums[mid] && target<=nums[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        //左边有序数组
        else{
            if(target>= nums[0] && target<=nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
    }
    return -1;
}


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target=0;
    int ans=search(nums,target);
    cout<<ans<<endl;

    system("pause");
    return 0;
}