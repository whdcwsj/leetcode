#include<bits/stdc++.h>
using namespace std;



int check(string a){
    int m=a.size();
    int res=0;
    int count=0;
    for(int i=0;i<m;i++){
        if(a[i]=='('){
            count++;
        }else{
            count--;
            if(count<0){
                res=0;
                break;
            }else if(count==0){
                res=i+1;
            }
        }
    }
    return res;
}




int main(){
    string s;
    cin>>s;
    int ans=0;
    int n=s.size();
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<s.substr(i).size();j++){
            ans+=check(s.substr(i,j));
            // record.push_back(s.substr(i,j));
        }
    }
    cout<<ans<<endl;

    system("pause");
    return 0;
}