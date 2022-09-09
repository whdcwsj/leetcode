#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            count+=1;
        }else{
            count-=1;
            if(count<0){
                break;
            }else if(count==0){
                res=i+1;
            }
        }
    }
    cout<<res<<endl;


    system("pause");
    return 0;
}