#include<bits/stdc++.h>
using namespace std;


//排序+贪心
int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int res=1;
    int cur=nums[0];
    for(int i=1;i<nums.size();i++){
        if(cur+k<nums[i]){
            cur=nums[i];
            res++;
        }
    }
    return res;
}



int main(){
    vector<int>nums = {3,6,1,2,5};
    int k=2;
    int ans=partitionArray(nums,k);
    cout<<ans<<endl;

    system("pause");
    return 0;
}