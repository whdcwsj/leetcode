#include<bits/stdc++.h>
using namespace std;



//题目要求10的7次方，那么大概是2的24次方可以完全表示candidates中的数
//找最多有多少个数字做按位与操作，他们的共同二进制位都是1
int largestCombination(vector<int>& candidates) {
    int res=0;
    //每一位
    for(int i=24;i>=0;i--){
        int count=0;
        for(int j=0;j<candidates.size();j++){
            if((candidates[j]>>i)&1){
                count++;
            }
        }
        res=max(res,count);
    }
    return res;
}



int main(){
    vector<int>candidates = {16,17,71,62,12,24,14};
    int ans=largestCombination(candidates);
    cout<<ans<<endl;
    
    system("pause");
    return 0;
}