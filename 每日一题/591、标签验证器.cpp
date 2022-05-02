#include<bits/stdc++.h>
using namespace std;

//字符串匹配为问题，常用栈
bool isValid(string code) {
    stack<string>s;
    for(int i=0;i<code.size();i++){
        //出现""
        if(i>0 && s.empty()) return false;
        //先匹配长度更长的字符
        //出现"<![CDATA["
        if(code.substr(i,9)=="<![CDATA["){
            int j=i+9;
            i=code.find("]]>",j);
            //中间包含的CDATA_CONTENT不用处理
            if(i==string::npos) return false;
            i+=2;
        }
        //匹配末尾
        //出现"</"
        else if(code.substr(i,2)=="</"){
            int j=i+2;
            i=code.find(">",j);
            if(i==string::npos) return false;
            string tag=code.substr(j,i-j);
            if(s.empty() || s.top()!=tag) return false;
            s.pop();
        }
        //匹配开头
        //出现"<"
        else if(code.substr(i,1)=="<"){
            int j=i+1;
            i=code.find(">",j);
            //长度[1,9]
            if(i==string::npos || i-j>9 || j-i==0) return false;
            //大写判断
            for(int k=j;k<i;k++){
                if(isupper(code[k])==false) return false;
            }
            string tag=code.substr(j,i-j);
            s.push(tag);
        }
    }
    return s.empty();
}


int main(){
    string co="<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    bool flag=isValid(co);
    cout<<flag<<endl;

    system("pause");
    return 0;
}