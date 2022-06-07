#include<bits/stdc++.h>
using namespace std;


//不允许乘除，不允许条件判断语句
//1、递归
int sumNums(int n) {
    n && (n+=sumNums(n-1));
    return n;
}


//2、快速乘
//考虑A和B两数相乘的时候如何利用加法和位运算来模拟
//其实就是将B二进制展开，如果B的二进制表示下第i位为1那么这一位对最后结果的贡献就是A∗(1<<i)，即A<<i



int main(){
    int n=9;
    int ans=sumNums(n);
    cout<<ans<<endl;

    system("pause");
    return 0;
}