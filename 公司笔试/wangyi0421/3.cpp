#include<bits/stdc++.h>
using namespace std;


vector<int>zhishu;
bool isPrime(int x){
    if(x<=1) return false;
    bool flag=true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}

void judge(int x,int y){
    for(int i=x;i<=y;i++){
        if(isPrime(i)){
            zhishu.push_back(i);
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<int>nums;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        nums.push_back(num);
    }
    if(n==1){
        if(isPrime(nums[0]) && nums[0]!=2){
            cout<<0<<endl;
            return 0;
        }else{
            cout<<1<<endl;
            return 0;
        }
    }
    sort(nums.begin(),nums.end());
    judge(nums[0],nums[n-1]);
    int res=0;
    //说明序列都在两个质数之间
    if(zhishu.size()==0){
        //全是1的话
        if(nums[n-1]==1){
            cout<<n*2<<endl;
            return 0;
        }else{
            cout<<n<<endl;
            return 0;
        }
    }
    if(zhishu.size()==1){
        if(zhishu[0]==2){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==2){
                    res++;
                }else{
                    res+=2;
                }
            }
        }else{
            res=n;
        }
    }
    map<int,vector<int>>wang;
    for(int i=0;i<n;i++){
        
    }


    cout<<res<<endl;

    system("pause");
    return 0;
}