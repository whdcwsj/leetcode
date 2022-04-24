#include<bits/stdc++.h>
using namespace std;

int main(){
    long long p,q;
    cin>>p>>q;
    //保证p小于q
    p=p%q;

    //记录每个余数对应的数字
    // vector<int>flag(1000,-1);
    //第一个还剩下数字的对应的除余结果，第二个是还剩下的数字对应的位置
    vector<vector<int>>flag(1000,vector<int>(2,-1));

    int k=0;
    int length=0;
    //记录循环节的起始位置
    int index=0;
    long long c;
    //看小数
    while(true){
        c=(p*10);
        p=c%q;
        //如果整除了,2,5
        if(p==0){
            length=0;
            index=-1;
            break;
        }
        //该余数重复出现过
        if(flag[p][1]>=0){
            if(flag[p][0]==c/q){
                index=flag[p][1];
                length=k-index;
                break;
            }
        }
        flag[p][0]=c/q;
        flag[p][1]=k;
        k++;
    }
    if(index==-1){
        cout<<-1<<endl;
    }else{
        cout<<index<<" ";
        cout<<length<<endl;
    }


    system("pause");
    return 0;
}