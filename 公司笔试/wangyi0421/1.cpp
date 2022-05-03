#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<double>nums;
    double num;
    while(n--){
        cin>>num;
        nums.push_back(num);
    }
    int res=0;
    if(nums.size()==1){
        cout<<res<<endl;
        return 0;
    }
    sort(nums.begin(),nums.end());
    bool flag=true;
    double avg;
    while(flag){
        flag=false;
        avg=0;
        for(int i=0;i<nums.size();i++){
            avg+=double(nums[i]);
        }
        avg=avg/double(nums.size());
        //cout<<"avg="<<avg<<endl;
        for(int j=nums.size()-1;j>=0;j--){
            //cout<<nums[j]<<endl;
            if(nums[j]>avg){
                flag=true;
                nums.erase(nums.begin()+j);
            }
        }
        if(flag==true) res++;
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}