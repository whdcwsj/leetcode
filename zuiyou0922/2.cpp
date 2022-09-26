#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>nums;
    string s;
    while(getline(cin,s,' ')){
        nums.push_back(stoi(s));
    }

    int n=nums.size();
    vector<int>res;
    //从右往左找当前位置，以及之后最小的
    vector<int>right_min(n,-1);
    int right_xiao=nums[n-1];
    for(int i=n-1;i>=0;i--){
        if(nums[i]<right_xiao){
            right_xiao=nums[i];
        }
        right_min[i]=right_xiao;
    }
    //从左往右，找比左边大，同时比右边小的数字
    int left_big=nums[0];
    for(int i=0;i<n-1;i++){
        if(nums[i]>left_big){
            left_big=nums[i];
            if(nums[i]<right_min[i+1]){
                res.push_back(nums[i]);
            }
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i<res.size()-1) cout<<" ";
    }

    system("pause");
    return 0;
}