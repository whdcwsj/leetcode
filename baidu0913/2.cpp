#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>operation(m,vector<int>(2)),wang({{0,0}});
    for(int i=0;i<m;i++){
        cin>>operation[i][0]>>operation[i][1];
    }
    //有用的操作记录
    int temp=0;
    for(int i=m-1;i>=0;i--){
        if(operation[i][1]>temp){
            wang.push_back(operation[i]);
            temp=operation[i][1];
        }
    }

    vector<int>solder=nums;
    sort(solder.begin(),solder.begin()+wang.back()[1]);
    //solder的序号
    int left=0;
    int right=wang.back()[1]-1;

    int index=right;
    int cur=wang.back()[1];
    int next;
    //均是从右到左赋值
    for(int i=wang.size()-1;i>0;i--){
        next=wang[i-1][1];
        //赋值最小的
        if(wang[i][0]==2){
            cout<<"i:"<<i<<endl;
            cout<<"wang"<<endl;
            for(int j=0;j<(cur-next);j++){
                nums[index]=solder[left];
                cout<<"nums[]"<<index<<" "<<solder[left]<<endl;
                cout<<"cur_pre"<<index<<endl;
                index--;
                cout<<"cur_after"<<index<<endl;
                left++;
            }
        //赋值最大的
        }else if(wang[i][0]==1){
            cout<<"i:"<<i<<endl;
            cout<<"si"<<endl;
            for(int j=0;j<(cur-next);j++){
                nums[index]=solder[right];
                cout<<"nums[]"<<index<<" "<<solder[right]<<endl;
                cout<<"cur_pre"<<index<<endl;
                index--;
                cout<<"cur_after"<<index<<endl;
                right--;
            }
        }
        cur=next;
    }
    for(auto&a:nums){
        cout<<a<<" ";
    }




    system("pause");
    return 0;
}