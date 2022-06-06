#include<bits/stdc++.h>
using namespace std;


//f(n, m)表示，n个人报数，每报到m时杀掉那个人，返回最终胜利者的编号
//杀掉一个人，相当于把数组向前移动m个位置
int f(int n,int m){
    if(n==1) return 0;
    return (f(n-1,m)+m)%n;
}


int lastRemaining(int n, int m) {
    return f(n,m);
}


//优化空间，不递归
int lastRemaining(int n, int m) {
    //剩下一个人，胜利者下标是0
    int f=0;
    for(int i=2;i<=n;i++){
        f=(f+m)%i;
    }
    return f;
}




int main(){
    int n = 10, m = 17;
    int ans=lastRemaining(n,m);
    cout<<ans<<endl;

    system("pause");
    return 0;
}