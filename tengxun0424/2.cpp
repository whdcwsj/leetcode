#include<bits/stdc++.h>
using namespace std;

int main(){
    int c;
    cin>>c;
    vector<double>f;
    vector<vector<double>>quan(c,vector<double>(c,0));
    double num;
    for(int i=0;i<c;i++){
        cin>>num;
        f.push_back(num);
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            cin>>num;
            quan[i][j]=num;
        }
    }
    vector<double>res;
    double sum=0;
    double a;
    double b;
    double maxnum=double(INT_MIN);
    vector<int>id;
    //int id=-1;
    for(int i=0;i<c;i++){
        sum=0.0;
        a=f[i];
        for(int j=0;j<c;j++){
            b=quan[j][i];
            sum+=a*b;
        }
        //cout<<"i="<<i<<"sum"<<sum<<endl;
        if(sum==maxnum){
            id.push_back(i);
        }
        if(sum>maxnum){
            maxnum=sum;
            //id=i;
            id.clear();
            id.push_back(i);
        }
    }
    //cout<<id<<endl;
    for(int i=0;i<id.size();i++){
        cout<<id[i];
        if(i<id.size()-1) cout<<" ";
    }

    system("pause");
    return 0;
}