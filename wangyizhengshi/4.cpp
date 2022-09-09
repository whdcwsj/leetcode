#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;


int main(){
    long long a,b,n;
    cin>>a>>b>>n;
    if(n==1){
        cout<<a%N<<endl;
        return 0;
    }
    if(n==2){
        cout<<b%N<<endl;
    }
    
    // double c0=b+(sqrt(3)-1)*a;
    // n--;
    n-=2;
    a=a%N;
    b=b%N;
    long long res=1;
    while(n--){
        res=(a*a)%N;
        res=(res*b)%N;
        res=(res*b)%N;
        a=b;
        b=res;
    }
    cout<<res<<endl;
    
    
    system("pause");
    return 0;
}