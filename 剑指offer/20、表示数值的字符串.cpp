#include<bits/stdc++.h>
using namespace std;

//至少一位整数
bool oneIntCheck(string s,int& index){
    int cur=index;
    while(index!=s.size() && (s[index]>='0' && s[index]<='9')){
        index++;
    }
    return index>cur;
}

//整数检测
bool intCheck(string s,int& index){
    if(s[index]=='+'||s[index]=='-'){
        index++;
    }
    //符号后面直接结尾
    if(index>=s.size()) return false;
    //符号连续出现，有问题
    if(s[index]=='+'||s[index]=='-'){
        return false;
    }
    return oneIntCheck(s,index);
}

bool isNumber(string s) {
    if(s.size()==0) return false;
    int n=s.size();
    int i=0;
    while(s[i]==' '){
        i++;
    }
    //全是空格
    if(i>=n) return false;
    //直接整数?
    bool flag=intCheck(s,i);
    
    // cout<<"1:"<<"index:"<<i<<" flag:"<<flag<<endl;

    //小数部分，有小数点
    if(s[i]=='.'){
        i++;
        cout<<"haha:"<<i<<endl;
        flag= oneIntCheck(s,i) || flag;
    }

    //cout<<"2:"<<"index:"<<i<<" flag:"<<flag<<endl;

    //数值的指数部分
    if(s[i]=='E' || s[i]=='e'){
        i++;
        if(i>=n) return false;
        flag= flag && intCheck(s,i);
    }

    //字符串末尾的空格
    while(s[i]==' '){
        i++;
    }
    return flag && i==s.size();
}


int main(){
    string s = "0.8";
    bool ans=isNumber(s);
    cout<<ans<<endl;

    system("pause");
    return 0;
}