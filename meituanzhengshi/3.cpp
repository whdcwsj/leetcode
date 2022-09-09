#include<bits/stdc++.h>
using namespace std;


// 这个做法不可取
// int main(){
//     int n;
//     cin>>n;
//     vector<int>nums(n,0);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     if(n==1) cout<<nums[0]<<endl;
//     if(n==2) cout<<nums[0]<<" "<<nums[1]<<endl;
//     if(n>=3){
//         vector<bool>flag(n,0);
//         vector<int>res(n,0);
//         int index=-1;
//         for(int i=0;i<n;i++){
//             while(flag[(index+1)%n]==1){
//                 index++;
//             }
//             index=(index+1)%n;
//             while(flag[(index+1)%n]==1){
//                 index++;
//             }
//             index=(index+1)%n;
//             while(flag[(index+1)%n]==1){
//                 index++;
//             }
//             index=(index+1)%n;
//             // cout<<"i:"<<i<<endl;
//             // cout<<"当前Index:"<<index<<endl;
//             if(flag[index]==0){
//                 res[index]=nums[i];
//                 flag[index]=1;
//             }
//         }
//         for(int j=0;j<n;j++){
//             cout<<res[j];
//             if(j<n-1) cout<<" ";
//         }
//         cout<<endl;
//     }


//     system("pause");
//     return 0;
// }



int main(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int num=0;

    //双端队列
    deque<int>q;
    //倒着走流程
    int i=n-1;
    while(i>=0){
        num=nums[i];
        q.push_front(num);
        if(q.size()>1){
            num=q.back();
            q.pop_back();
            q.push_front(num);

            num=q.back();
            q.pop_back();
            q.push_front(num);
        }
        i--;
    }
    for(int i=0;i<n;i++){
        cout<<q[i];
        if(i<n-1) cout<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}