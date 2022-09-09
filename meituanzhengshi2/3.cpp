#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>gailv(n,0);
    for(int i=0;i<n;i++){
        cin>>gailv[i];
    }
    vector<int>score(n,0);
    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    double res=0;
    for(int i=0;i<n;i++){
        res+=gailv[i]*score[i];
    }
    vector<double>shengyu(n,0);
    for(int i=0;i<n;i++){
        shengyu[i]=(double)(score[i]*(100-gailv[i]));
    }
    sort(shengyu.begin(),shengyu.end());
    while(m){
        res+=shengyu[--n];
        m--;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<res/100.0<<endl;
    


    system("pause");
    return 0;
}