#include<bits/stdc++.h>
using namespace std;


int binary_search(vector<int>&nums,int target, bool first){
    int n=nums.size();
    int left=0;
    int right=n-1;
    int res=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>target || (first && nums[mid]>=target)){
            right=mid-1;
            res=mid;
        }else{
            left=mid+1;
        }
    }
    return res;
}


int main(){
    vector<int>nums={};
    int target=0;
    int first_result=binary_search(nums,target,true);
    int end_result=binary_search(nums,target,false)-1;
    if(first_result<=end_result && end_result<=nums.size() && nums[first_result]==target && nums[end_result]==target){
        cout<<first_result<<" "<<end_result<<endl;
    }else{
        cout<<-1<<" "<<-1<<endl;
    }

    system("pause");
    return 0;
}