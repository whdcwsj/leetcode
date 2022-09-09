#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());
    if(k==1) return nums.front();

    int bianjie=nums[k-1];
    int index=-1;
    for(int i=31;i>=0;i--){
        if(bianjie&(1<<i)!=0){
            index=i;
            break;
        }
    }
    // cout<<"bianjie:"<<bianjie<<endl;
    // cout<<"index:"<<index<<endl;
    vector<int>big;
    for(int i=0;i<k;i++){
        big.push_back(nums[i]);
    }
    vector<int>count(index+1,0);
    for(auto &num:big){
        for(int i=0;i<=index;i++){
            if((num&(1<<i))!=0){
                count[i]++;
            }
        }
    }
    int res=0;
    int chengshu=1;
    for(int i=0;i<=(index+1);i++){
        if(count[i]==k){
            res+=chengshu;
        }
        chengshu*=2;
    }
    cout<<res<<endl;

    // for(auto a:count){
    //     cout<<a<<" ";
    // }



    system("pause");
    return 0;
}