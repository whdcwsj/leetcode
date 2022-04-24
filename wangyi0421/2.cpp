#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        nums[i]=num;
    }
    //记录每个节点的父节点
    map<int,int>relation;
    for(int i=1;i<n;i++){
        cin>>num;
        relation[i]=num;
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    vector<int>res(n,0);
    res[0]=1;
    for(int i=1;i<n;i++){
        //子节点小于父节点
        if(nums[i]<=nums[relation[i]-1]){
            res[i]=i+1;
        }
        //子节点大于父节点
        else{
            res[i]=res[relation[i]-1];
        }
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i<res.size()-1){
            cout<<" ";
        }
    }

    system("pause");
    return 0;
}