#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    vector<long long>nums;
    for(int i=0;i<t;i++){
        long long temp;
        cin>>temp;
        nums.push_back(temp);
    }

    vector<long long>res(t,0);
    // for(int i=0;i<t;i++){
    //     long long temp=(long long)sqrt(nums[i])+1;
    //     for(long long j=temp;j<=nums[i];j++){
    //         // cout<<j<<endl;
    //         if(nums[i]%j==0){
    //             res.push_back(j);
    //             break;
    //         }
    //     }
    // }
    for(int i=0;i<t;i++){
        long long left=(long long)sqrt(nums[i])+1;
        long long right=nums[i]+1;
        while(left<right){
            long long mid=(right-left)/2+left;
            if(nums[i]%mid==0){
                res[i]=mid;
                right=mid-1;
            }else if(){
                left=mid;
            }
        }


    }
    for(int i=0;i<t;i++){
        cout<<res[i]<<endl;
    }

    system("pause");
    return 0;
}