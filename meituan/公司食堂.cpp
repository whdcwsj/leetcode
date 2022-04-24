#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int m;
        cin>>m;
        string member;
        cin>>member;
        //定义两个优先队列来记录0人桌子和一人桌子
        //升序序列，小顶堆，ID最小的桌子
        priority_queue<int,vector<int>,greater<int>>q1;
        priority_queue<int,vector<int>,greater<int>>q2;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                q1.push(i+1);
            }else if(s[i]=='1'){
                q2.push(i+1);
            }
        }

        for(int i=0;i<member.size();i++){
            if(member[i]=='M'){
                if(!q2.empty()){
                    int temp=q2.top();
                    q2.pop();
                    cout<<temp<<endl;
                }else{
                    int temp=q1.top();
                    q1.pop();
                    cout<<temp<<endl;
                    q2.push(temp);
                }
            }else{
                if(!q1.empty()){
                    int temp = q1.top();
                    q1.pop();
                    cout<<temp<<endl;
                    q2.push(temp);
                }
                else{
                    int temp = q2.top();
                    q2.pop();
                    cout<<temp<<endl;
                }
            }
        }
    }

    system("pause");
    return 0;

}