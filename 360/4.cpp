#include<bits/stdc++.h>
using namespace std;


//升序，小的在前
static bool cmp1(const int&a,const int&b){
    return a<b;
}

//降序，大的在前
static bool cmp2(const int&a,const int&b){
    return a>b;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>nums(n,-1);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<pair<int,int>>record;
    for(int i=0;i<m;i++){
        int t;
        int x;
        cin>>t>>x;
        record.push_back(pair<int,int>(t,x));
    }

    for(int i=0;i<m;i++){
        if(record[i].first==0){
            sort(nums.begin(),nums.begin()+record[i].second,cmp1);
        }else{
            sort(nums.begin(),nums.begin()+record[i].second,cmp2);
        }
    }

    int w=nums.size();
    for(int j=0;j<w;j++){
        cout<<nums[j];
        if(j<w-1) cout<<" ";
    }
    cout<<endl;


    system("pause");
    return 0;
}