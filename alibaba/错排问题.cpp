#include<iostream>;
using namespace std;

//错排问题
int wrongNum(int N){
    if(N==1) return 0;
    if(N==2) return 1;
    else return (N-1)*(wrongNum(N-1)+wrongNum(N-2));
}

int main(){
    int n;
    cin>>n;
    int res=wrongNum(n);
    cout<<res<<endl;
}

