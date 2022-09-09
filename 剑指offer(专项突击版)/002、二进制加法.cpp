#include<bits/stdc++.h>
using namespace std;


//倒着处理字符串，再反转
string addBinary(string a, string b) {
    //注意减一
    int lena=a.size()-1;
    int lenb=b.size()-1;
    string res;
    //进位
    int wang=0;
    while(lena>=0 || lenb>=0 || wang!=0){
        if(lena>=0){
            wang+=a[lena--]-'0';
        }
        if(lenb>=0){
            wang+=b[lenb--]-'0';
        }
        //可能产生两个进位
        res+=(wang%2)+'0';
        wang/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}




int main(){
    string a = "1010", b = "1011";
    string res=addBinary(a,b);
    for(auto&a:res){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}
