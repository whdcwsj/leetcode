#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>nums;
    string s;
    while(getline(cin,s,' ')){
        nums.push_back(stoi(s));
    }
    // cout<<"n:"<<nums.size()<<endl;
    int n=nums.size();
    if(n==0) return 0;
    //双指针
    int fast=1;
    int slow=1;
    while(fast<n){
        if(nums[fast]!=nums[fast-1]){
            nums[slow]=nums[fast];
            slow++;
        }
        fast++;
    }
    cout<<slow<<endl;

    system("pause");
    return 0;
}