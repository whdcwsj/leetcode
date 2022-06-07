#include<bits/stdc++.h>
using namespace std;



//int的取值范围：-2147483648~2147483647

int strToInt(string str) {
    //边界值
    int border=INT_MAX/10;
    //去除开头的空格
    int i=0;
    while(i<str.size() && str[i]==' ') i++;
    //判断符号
    bool sign=0;
    if(str[i]=='-') sign=1;
    if(str[i]=='-'|| str[i]=='+') i++;
    //数字拼接
    int res=0;
    for(int j=i;j<str.size();j++){
        //非数字，跳出
        // cout<<"i:"<<i<<endl;
        // cout<<isdigit(str[j])<<endl;
        if(!isdigit(str[j])) break;
        else{
            if(res>border || (res==border && str[j]>'7')){
                return sign?INT_MIN:INT_MAX;
            }
            res=res*10+(str[j]-'0');
        }
    }
    return sign?res*(-1):res;
}


int main(){
    //string str="   -42";
    string str="4193 with words";
    int ans=strToInt(str);
    cout<<ans<<endl;

    system("pause");
    return 0;
}