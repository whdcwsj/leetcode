#include<bits/stdc++.h>
using namespace std;


// //这样会超时
// double myPow(double x, int n) {
//     int flag;
//     double res=1.0;

//     if(n==0){
//         return res;
//     }else if(n<0){
//         flag=-1;
//     }else{
//         flag=1;
//     }
//     n=abs(n);
//     while(n){
//         res*=x;
//         n--;
//     }
//     if(flag==1){
//         return res;
//     }else{
//         return 1.0/res;
//     }
// }


//☆快速幂做法
//快速幂法 可将时间复杂度降低至O(log2 n)
double myPow(double x, int n){
    if(x==0.0) return 0;
    double res=1;
    if(n<0){
        n=-n;
        x=1.0/x;
    }
    while(n){
        if(n&1){
            res*=x;
            x*=x;
            n>>=1;
        }
    }
    return res;
}


int main(){
    // double x = 2.10000;
    // int n = 3;
    double x = 2.00000;
    int n = -2147483648;
    double ans=myPow(x,n);
    cout<<ans<<endl;

    system("pause");
    return 0;
}