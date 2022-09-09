#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,t;
    cin>>n>>t;
    vector<int>deadline;
    int w=n;
    int num;
    while(w--){
        cin>>num;
        deadline.push_back(num);
    }
    sort(deadline.begin(),deadline.end());
    int res=0;
    int curtime=t;
    for(int i=0;i<n;i++){
        if(deadline[i]>=curtime){
            curtime+=t;
        }else{
            res++;
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}