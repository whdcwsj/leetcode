#include<bits/stdc++.h>
using namespace std;


int findMin(vector<int>& nums) {
    int n=nums.size();
    if(n==1){
        return nums.front();
    }
    int left=0,right=n-1;
    while(left<right){
        int mid=left+(right-left)/2;
        //cout<<mid<<endl;
        //最小值在左边
        if(nums[mid]<nums[right]){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return nums[left];
}


int main(){
    vector<int> nums = {3,4,5,1,2};
    int ans=findMin(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}