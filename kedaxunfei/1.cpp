#include<bits/stdc++.h>
#define PI 3.1415927
using namespace std;


long double hanwin(int x,long long num,int N){
    double res=0.5*(1-cos(2*PI*x/N))*num;
    if(res>0){
        return (long long)(res+0.5);
    }else if(res<0){
        return (long long)(res-0.5);
    }else{
        return (long long)(res);
    }
}


int main(){
    int n;
    cin>>n;
    vector<long long>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        cout<<hanwin(i,nums[i],n);
        if(i<n-1) cout<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}