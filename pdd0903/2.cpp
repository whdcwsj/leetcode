#include<bits/stdc++.h>
using namespace std;

int t;
vector<int>nums;
vector<vector<pair<char,int>>>zhiling(t,vector<pair<char,int>>{});

int search_check(int id,int length,int num){
    num++;
    //终止条件
    if(zhiling[id][length].first=='L' && length-zhiling[id][length].second<0){
        return num;
    }else if(zhiling[id][length].first=='R' && length+zhiling[id][length].second>=nums[id]){
        return num;
    }
    cout<<"length:"<<length<<",num:"<<num<<endl;

    if(zhiling[id][length].first=='L'){
        length=length-zhiling[id][length].second;
    }else{
        length+zhiling[id][length].second>=nums[id];
    }
    int next=search_check(id,length,num);
    // if(next==-1){
    //     num=-1;
    // }else{
    //     num=next;
    // }
    return next;
}


int main(){
    cin>>t;
    // vector<pair<char,int>>wang;
    // wang.push_back(make_pair<char,int>('L',1));
    // zhiling[0]=wang;
    // cout<<zhiling[0][0].first<<endl;
    // cout<<zhiling[0][0].second<<endl;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        nums.push_back(n);
        vector<pair<char,int>>wang;
        for(int j=0;j<n;j++){
            char c;
            int x;
            cin>>c>>x;
            wang.push_back(pair<char,int>(c,x));
        }
        zhiling[i]=wang;
    }
    //记录结果
    vector<vector<int>>res(t,vector<int>{});
    for(int i=0;i<t;i++){
        vector<int>temp_res(nums[i],0);
        // vector<bool>visited(nums[i],0);
        for(int j=0;j<nums[i];j++){
            int num=search_check(i,j,0);
            cout<<"temp_res"<<num<<endl;
            temp_res.push_back(num);
        }
        res.push_back(temp_res);
    }

    for(int i=0;i<t;i++){
        for(int j=0;j<nums[i];j++){
            cout<<res[i][j];
            if(j<nums[i]-1) cout<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}