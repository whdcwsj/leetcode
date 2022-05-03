#include<bits/stdc++.h>
using namespace std;


double sqrt_wang(double n){
    if(n<1){
        n=1;
    }
    double left=0;
    double right=n;
    double mid=n/2.0;
    while(abs(mid*mid-n)>0.000001){
        if(mid*mid<n){
            left=mid;
        }else{
            right=mid;
        }
        mid=(left+right)/2.0;
    }
    return mid;
}

int main(){
    int t;
    cin>>t;
    int a,b,c;
    double x;
    while(t--){
        cin>>a>>b>>c;
        x=0;
        double left=0.000001;
        double right=1000000.000002;
        double mid=(right+left)/2.0;
        while(abs(a*sqrt(mid)+b*log(mid)-c)>0.000001){
            if(a*sqrt_wang(mid)+b*log(mid)<c){
                left=mid;
            }else{
                right=mid;
            }
            mid=(left+right)/2.0;
        }
        cout<<fixed<<setprecision(8)<<mid<<endl;
    }


    system("pause");
    return 0;
}