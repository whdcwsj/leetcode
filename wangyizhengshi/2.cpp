#include<bits/stdc++.h>
using namespace std;

bool check(int start,int end,string s){
    string temp=s.substr(start,end-start+1);
    int r=0;
    int e=0;
    int d=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='r') r++;
        else if(temp[i]=='e') e++;
        else d++;
    }
    return r==e && e==d;
}


int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(n<=2) return 0;
    vector<string>record;
    for(int i=0;i<n-2;i++){
        for(int j=i+2;j<n;j+=3){
            if((j-i+1)%3==0){
                if(check(i,j,s)){
                    record.push_back(s.substr(i,j-i+1));
                }
            }
        }
    }
    cout<<record.size()<<endl;

    system("pause");
    return 0;
}