#include<bits/stdc++.h>
using namespace std;

set<vector<int>>wang;
vector<int>temp;

//计算满足条件的连续子数组数目
int countDistinct(vector<int>& nums, int k, int p) {
    int n=nums.size();
    int num;
    for(int i=0;i<n;i++){
        temp.clear();
        num=0;
        for(int j=i;j<n;j++){
            temp.push_back(nums[j]);
            if(nums[j]%p==0){
                num++;
                if(num>k) break;
            }
            wang.insert(temp);
        }
    }
    return wang.size();
}

int main(){
    vector<int> nums = {2,3,3,2,2};
    int k = 2;
    int p = 2;
    int hahaha=countDistinct(nums,k,p);
    cout<<hahaha<<endl;

    system("pause");
    return 0;
}