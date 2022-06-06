#include<bits/stdc++.h>
using namespace std;



int minMaxGame(vector<int>& nums) {
    while(true){
        int n=nums.size();
        if(n==1) break;
        else{
            vector<int>temp(n/2,0);
            for(int i=0;i<n/2;i++){
                if(i%2==0){
                    temp[i]=min(nums[2*i],nums[2*i+1]);
                }else{
                    temp[i]=max(nums[2*i],nums[2*i+1]);
                }
            }
            nums=temp;
        }
    }
    return nums[0];
}



int main(){
    vector<int>nums={1,3,5,2,4,8,2,2};
    int ans=minMaxGame(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}