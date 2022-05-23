#include<bits/stdc++.h>
using namespace std;



int findMin(vector<int>& nums) {
    int n=nums.size();
    if(n==1){
        return nums.front();
    }
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]<nums[right]){
            right=mid;
        }
        else if(nums[mid]>nums[right]){
            left=mid+1;
        }
        else{
            right--;
        }
    }
    return nums[left];
}


int main(){
    vector<int> nums = {2,2,2,0,1};
    int ans=findMin(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}