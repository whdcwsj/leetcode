#include<bits/stdc++.h>
using namespace std;



//二进制，本位操作，异或：相同为0，不同为1
//1+1=0,0+0=1,  1+0=1,0+1=1
//进位操作，&操作
//1+1+=1,   1+0=1,0+1=1,0+0=0

//例如:22+89=111
//  22
// +89
//  01 本位
//  11 进位
//  11*10+01=111 结果，10是进制数


int add(int a, int b) {
    while(b){
        //二进制下计算每一位的进位
        int carry=a&b;
        //二进制下计算每一位的本位
        a=a^b;
        //相当于*2
        //进位不存在 负 的情况，所以 unsigned 是修饰 进位
        b=(unsigned)carry<<1;
    }
    return a;
}



int main(){
    int a = 1, b = 1;
    int ans=add(a,b);
    cout<<ans<<endl;

    system("pause");
    return 0;
}