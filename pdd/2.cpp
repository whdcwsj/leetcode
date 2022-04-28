#include<bits/stdc++.h>
using namespace std;

int n;
string x,y;

int main(){
    cin>>n;
    cin>>x>>y;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int res=0;
    for(int i=0;i<n;i++){
        if(x[i]!=y[i]){
            res+=abs(x[i]-y[i]);
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}