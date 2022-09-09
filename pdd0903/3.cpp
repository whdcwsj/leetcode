#include<bits/stdc++.h>
using namespace std;


int main(){
    string s,t;
    cin>>s>>t;
    if(t.nsize()>s.size()){
        it n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                s[i]='a';
            }
        }
        cout<<s<<endl;
    }else{
        cout<<"baab"<<endl;
    }

    system("pause");
    return 0;
}