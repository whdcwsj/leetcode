#include<bits/stdc++.h>
using namespace std;


int mysearch(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(nums[i]>0 && nums[i]!=nums[nums[i]-1] && nums[i]<=n){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]!=(i+1)){
            return i+1;
        }
    }
    return n+1;
}


int main(){
    // vector<int>nums={3,4-1,1};
    // vector<int>nums={1,2,0};
    // vector<int>nums={7,8,9,10,11,12};
    vector<int>nums={-5,-6,-4};
    int res=mysearch(nums);
    cout<<res<<endl;


    system("pause");
    return 0;
}