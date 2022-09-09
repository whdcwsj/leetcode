#include<bits/stdc++.h>
using namespace std;

// long long gcd(long long a,long long b){
//     return a==0?b:gcd(b%a,a);
// }

// //小心溢出
// long long lcd(long long a,long long b){
//     return a/gcd(a,b)*b;
// }


int main(){
    int a,b,c;
    cin>>a>>b>>c;

    int all=a*b*c;
    for(int i=1;i<all;i++){
        if(i%a==0 && i%b==0 && i%c==0){
            cout<<i<<endl;
            break;
        }
    }


    system("pause");
    return 0;
}