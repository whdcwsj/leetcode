#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int res=0;
    while(cin>>s){
        res=0;
        s=s.substr(2);
        for(char&c:s){
            res*=16;
            if(c>='0' && c<='9'){
                res+=c-'0';
            }else{
                res+=c-'A'+10;
            }
        }
        cout<<res<<endl;
    }

    system("pause");
    return 0;
}