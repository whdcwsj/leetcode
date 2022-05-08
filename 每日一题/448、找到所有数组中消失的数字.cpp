#include<bits/stdc++.h>
using namespace std;


//抽屉原理
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(nums[i]!=nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    vector<int>res;
    for(int i=0;i<n;i++){
        if(nums[i]-1!=i){
            res.push_back(i+1);
        }
    }
    return res;
}