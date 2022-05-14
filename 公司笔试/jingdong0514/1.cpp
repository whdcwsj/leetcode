#include<bits/stdc++.h>
using namespace std;


vector<int>nums;
vector<int>res;

int main(){
    int n,k;
    cin>>n>>k;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // int k=4;
    // vector<int>temp={1,4,7,2,5,6,3};
    vector<int>com(nums.begin(),nums.begin()+k);
    sort(com.begin(),com.end());
    res.push_back(com[com.size()-k]);
    for(int i=k+1;i<=n;i++){
        com.push_back(nums[i-1]);
        sort(com.begin(),com.end());
        res.push_back(com[com.size()-k]);
    }
    int w=res.size();
    for(int j=0;j<w;j++){
        cout<<res[j];
        if(j<w-1){
            cout<<" ";
        }
    }


    system("pause");
    return 0;
}