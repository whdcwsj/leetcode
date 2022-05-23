#include<bits/stdc++.h>
using namespace std;


//以1234567为例子，计算百位上数位的1
//1234*100(先从千位上面看)
//末尾的再进行判断
int countDigitOne(int n) {
    //相当于初始10^0
    long long shuwei=1;
    int res=0;
    for(int k=0;shuwei<=n;k++){
        //高于当前数位的1的个数
        res+=(n/(shuwei*10))*shuwei;
        res+=min(max(n%(shuwei*10)-shuwei+1,(long long)0),shuwei);
        shuwei*=10;
    }
    return res;
}



int main(){
    int n=12;
    int ans=countDigitOne(n);

    cout<<ans<<endl;
    return 0;
}