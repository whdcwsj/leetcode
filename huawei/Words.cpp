#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    //这个样才能读入空格
    getline(cin,s);
    stringstream ss(s);
    string temp;
    double ans=0;
    int count=0;
    while(getline(ss,temp,' ')){
        ans+=temp.size();
        count++;
    }
    double wang=ans/count;
    // cout<<fixed<<setprecision(2)<<wang<<endl;
    printf("%.2f\n",wang);

    system("pause");
    return 0;
}