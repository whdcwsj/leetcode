#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string a;
    string b;
    cin>>a;
    cin>>b;
    string res;
    for(int i=0;i<n;i++){
        res.push_back(a[i]);
        res.push_back(b[i]);
    }

    cout<<res<<endl;

    system("pause");
    return 0;
}