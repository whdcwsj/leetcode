#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            res++;
        }
    }
    cout<<res<<endl;;

    system("pause");
    return 0;
}