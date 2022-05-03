#include<bits/stdc++.h>
using namespace std;


bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    //降序排列
    return a.first>b.first;
}


int main(){
    vector<pair<int,int>>res={{3,2},{4,1},{2,6}};
    sort(res.begin(),res.end(),cmp);
    for(auto a:res){
        cout<<a.first<<endl;
    }
}