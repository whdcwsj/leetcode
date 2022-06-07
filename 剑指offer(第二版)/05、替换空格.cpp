#include<bits/stdc++.h>
using namespace std;

//时间复杂度O(N):遍历统计、遍历修改
string replaceSpace(string s){
    int n=s.size();
    int count=0;
    for(char &c:s){
        if(c==' ') count++;
    }
    int new_n=n+count*2;
    s.resize(new_n);
    //倒着赋值
    for(int i=n-1,j=new_n-1;i<j;i--,j--){
        if(s[i]==' '){
            s[j]='0';
            s[j-1]='2';
            s[j-2]='%';
            j-=2;
        }else{
            s[j]=s[i];
        }
    }
    return s;
}


int main(){
    string s = "We are happy.";
    string ans=replaceSpace(s);
    cout<<ans<<endl;

    system("pause");
    return 0;
}