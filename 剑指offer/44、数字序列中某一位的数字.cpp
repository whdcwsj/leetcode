#include<bits/stdc++.h>
using namespace std;


//从第0位算起
//1*9+1
//2*90
//3*900
int findNthDigit(int n) {
    if(n<10) return n;
    //起始数字
    long long start=1;
    //数位
    int digit=1;
    //当前数位下的数字和
    long long count=9;
    while(n>count){
        n-=count;
        digit++;
        start*=10;
        count=9*start*digit;
    }
    int num=start+(n-1)/digit;
    count=(n-1)%digit;
    string s=to_string(num);
    cout<<"count: "<<count<<endl;
    return s[count]-'0';
}


int main(){
    int n=11;
    int ans=findNthDigit(n);
    cout<<ans<<endl;

    system("pause");
    return 0;
}