#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>nums;
    vector<int>chafen;
    map<int,int>wang;

    int n;
    cin>>n;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    chafen.resize(n-1);
    int maxcount=1;
    for(int i=1;i<n;i++){
        chafen[i-1]=abs(nums[i]-nums[i-1]);
        wang[chafen[i-1]]++;
        if(wang[chafen[i-1]]>maxcount){
            maxcount=wang[chafen[i-1]];
        }
    }
    int minnum=wang.begin()->first;
    int maxnum=wang.rbegin()->first;
    //cout<<"xiao "<<minnum<<" da "<<maxnum<<endl;

    //判断是否连续数字都有
    bool flag=true;
    int queshi=0;
    for(int i=minnum;i<=maxnum;i++){
        if(wang.find(i)==wang.end()){
            flag=false;
            queshi++;
        }
    }
    //cout<<"flag"<<flag<<endl;
    //正确
    if(maxcount==1 && flag){
        cout<<"YES"<<endl;
        cout<<minnum<<" "<<maxnum<<endl;
    }else{
        cout<<"NO"<<endl;
        cout<<maxcount<<" "<<queshi<<endl;
    }


    system("pause");
    return 0;
}