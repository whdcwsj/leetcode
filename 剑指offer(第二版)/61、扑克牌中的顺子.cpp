#include<bits/stdc++.h>
using namespace std;



//没有大小王，nums[4]-nums[wanneng]==4
//有大小王,nums[4]-nums[wanneng]<5
bool isStraight(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int wanneng=0;
    for(int i=0;i<4;i++){
        if(nums[i]==0) wanneng++;
        else{
            if(nums[i]==nums[i+1]){
                return false;
            }
        }
    }
    return nums[4]-nums[wanneng]<5;
}


int main(){
    vector<int>nums={1,2,3,4,5};
    bool flag=isStraight(nums);
    cout<<flag<<endl;

    system("pause");
    return 0;
}