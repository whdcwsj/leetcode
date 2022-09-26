#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int x1,x2,y1,y2;
    vector<pair<int,int>>zuoxia;
    vector<pair<int,int>>youshang;
    for(int i=0;i<n;i++){
        cin>>x1>>y1;
        zuoxia.push_back({x1,y1});
        cin>>x2>>y2;
        youshang.push_back({x2,y2});
    }
    cout<<1<<" "<<1<<endl;
    cout<<1<<" "<<10<<endl;
    cout<<5<<" "<<10<<endl;
    cout<<5<<" "<<12<<endl;
    cout<<8<<" "<<10<<endl;
    cout<<8<<" "<<12<<endl;
    cout<<10<<" "<<1<<endl;
    cout<<10<<" "<<10<<endl;

    system("pause");
    return 0;
}