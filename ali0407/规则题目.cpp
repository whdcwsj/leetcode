#include<bits/stdc++.h>
using namespace std;
const long long maxnum=1e9+1;

int main(){
    int n;
    long long a;
    vector<int>nums;
    map<long long,int>wang;

    cin>>n;
    while(n--){
        cin>>a;
        nums.push_back(a);
    }
    for(auto &b:nums){
        wang[b]++;
    }
    long long temp=1e4;
    long long res=0;
    for(long long i=1;i<temp;i++){
        while(wang[i]>=2){
            wang[i]-=2;
            wang[i+i]++;
            if(i*2-temp>0) temp=i*2;
            else res=max(res,2*i);
        }
    }
    if(temp!=1e4) cout<<temp<<endl;
    else cout<<res<<endl;
    
    // system("pause");
    return 0;
}