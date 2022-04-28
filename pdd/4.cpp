#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> nums;
unordered_map<int, int> res;
vector<int>wang;

//骰子，按对顺序调整位置，不改变顺序，123456,345612一样
//固定上方的面为1，剩下一圈的数字相同（左，前，右，后），则两个骰子一模一样
//以一圈数字中最小的数字作为字典的key数值
int main(){
    cin>>n;
    nums.resize(n,vector<int>(6));
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin>>nums[i][j];
        }
        int val=0;
        for(int j=0;j<6;j++){
            if(nums[i][j]==1){
                if(j%2==0){
                    val=nums[i][(j+2)%6]*1000+nums[i][(j+4)%6]*100+nums[i][(j+3)%6]*10+nums[i][(j+5)%6];
                }else{
                    val=nums[i][(j+3)%6]*1000+nums[i][(j+1)%6]*100+nums[i][(j+4)%6]*10+nums[i][(j+2)%6];
                }
                break;
            }
        }
        //记录最小的数值
        int temp=val;
        for(int j=0;j<3;j++){
            temp=temp/10+temp%10*1000;
            val=min(temp,val);
        }
        res[val]++;
    }
    cout<<res.size()<<endl;
    for(auto&a:res){
        wang.push_back(a.second);
    }
    sort(wang.begin(),wang.end());
    for(int i=res.size()-1;i>=0;i--){
        cout<<wang[i]<<" ";
    }

    system("pause");
    return 0;
}