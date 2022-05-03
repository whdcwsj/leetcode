#include<bits/stdc++.h>
using namespace std;

//方法一：hash表记录
int findRepeatNumber(vector<int>& nums){
    int n=nums.size();
    vector<int>count(n);
    for(int i=0;i<n;i++){
        count[nums[i]]++;
        if(count[nums[i]]>1){
            return nums[i];
        }
    }
    return -1;
}


int main(){
    vector<int>nums={2, 3, 1, 0, 2, 5, 3};
    int ans=findRepeatNumber(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}