#include<bits/stdc++.h>
using namespace std;


int main(){
    int c;
    cin>>c;
    vector<double>f(c);
    vector<vector<double>>d(c,vector<double>(c));
    for(int i=0;i<c;i++){
        cin>>f[i];
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            cin>>d[i][j];
        }
    }
    vector<double>res(c);
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            res[i]+=f[j]*d[i][j];
        }
    }
    cout<<max_element(res.begin(),res.end())-res.begin()<<endl;

    system("pause");
    return 0;
}