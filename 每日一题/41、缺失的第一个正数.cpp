#include<bits/stdc++.h>
using namespace std;

//抽屉原理
//可以只负责处理[1,N]之间的正数，不在的不处理，这样对应的位置就是第一个正数
int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for(int i=0;i<n;i++){
        //因为nums[i]存在-2^31的情况，不能再减一
        if(nums[i]!=i+1){
            return i+1;
        }
    }
    return n+1;
}



int main(){
    vector<int> nums = {7,8,9,11,12};
    int ans=firstMissingPositive(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}