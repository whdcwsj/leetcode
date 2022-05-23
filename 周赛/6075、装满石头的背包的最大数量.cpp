#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n=capacity.size();
    vector<int>other(n);
    for(int i=0;i<n;i++){
        other[i]=capacity[i]-rocks[i];
    }
    cout<<"wang"<<endl;
    sort(other.begin(),other.end());
    int res=0;
    int id=0;
    while(additionalRocks>=0){
        if(id>=n) break;
        if(other[id]<=additionalRocks){
            res++;
            additionalRocks-=other[id];
        }else{
            break;
        }
        id++;
    }
    return res;
}


int main(){
    vector<int>capacity = {10,2,2};
    vector<int> rocks = {2,2,0};
    int additionalRocks = 100;
    int ans=maximumBags(capacity,rocks,additionalRocks);
    cout<<ans<<endl;


    system("pause");
    return 0;
}