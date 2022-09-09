#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    unordered_map<int,vector<int>>m;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        m[3*nums[i]].push_back(i);
    }
    int res=0;
    for(int i=0;i<n-2;i++){
        //对应k
        for(int j=n-1;j>i+1;j--){
            int temp=nums[i]+nums[j];
            if(m.find(temp)!=m.end()){
                auto& wang=m[temp];
                int index1=upper_bound(wang.begin(),wang.end(),i)-wang.begin();
                int index2=lower_bound(wang.begin(),wang.end(),j)-wang.begin();
                res+=index2-index1;
            }
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}