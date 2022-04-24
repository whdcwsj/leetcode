#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    double num;
    double win;
    //自己的钱
    double sum=n;
    int duishou;
    while(m--){
        cin>>num;
        win=num;
        sum=(double)sum;
        duishou=floor((sum/(1-win)-sum));
        if((duishou+sum)*(1-win)-sum<0.000001){
            duishou--;
        }
        sum=sum+duishou;
        sum=(int)sum;
    }
    cout<<(int)sum<<endl;

    system("pause");
    return 0;
}