#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int count=0;
    bool flag=false;

    while(flag==false){
        //保证a大b小
        if(a<b) swap(a,b);
        if(a==b){
            flag=true;
        }
        else if(a==b*2 || a==b*2+1 || a==b+1){
            count++;
            flag=true;
        }
        else if(a>b*2+1){
            count++;
            a=a/2;
        }
        else if(a>b+1 && a<b*2){
            if(b<=5){
                count+=2;
                flag=true;
            }
            else if(b>6 && a-b==2){
                count+=2;
                flag=true;
            }
            else if(b>6 && (a==b*2-1 || a==b*2-2)){
                count+=2;
                flag=true;
            }
            else{
                count++;
                a=a/2;
            }
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}