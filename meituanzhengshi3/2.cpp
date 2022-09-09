#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>caozuo(m,0);
    for(int i=0;i<m;i++){
        cin>>caozuo[i];
    }
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        nums[i]=i+1;
    }
    reverse(nums.begin(),nums.end());

    for(int i=0;i<m;i++){
        nums.erase(remove(nums.begin(),nums.end(),caozuo[i]),nums.end());
        nums.push_back(caozuo[i]);
    }
    for(int i=n-1;i>=0;i--){
        cout<<nums[i];
        if(i>0) cout<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}