#include<bits/stdc++.h>
using namespace std;


//二分查找，这个边界值不好找
int missingNumber(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    //必须用闭区间
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==mid) left=mid+1;
        else right=mid-1;
    }
    return left;
}


int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,9};
    int ans=missingNumber(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}