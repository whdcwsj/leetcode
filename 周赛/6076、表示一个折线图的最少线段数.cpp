#include<bits/stdc++.h>
using namespace std;


static bool cmp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}


int minimumLines(vector<vector<int>>& stockPrices) {
    int res=1;
    int n=stockPrices.size();
    if(n==1) return 0;
    if(n==2) return res;
    sort(stockPrices.begin(),stockPrices.end(),cmp);
    long long x_dis=stockPrices[1][0]-stockPrices[0][0];
    long long y_dis=stockPrices[1][1]-stockPrices[0][1];
    long long temp_x;
    long long temp_y;
    for(int i=2;i<n;i++){
        temp_x=stockPrices[i][0]-stockPrices[i-1][0];
        temp_y=stockPrices[i][1]-stockPrices[i-1][1];
        if((y_dis*temp_x)!=(temp_y*x_dis)){
            res++;
        }
        x_dis=temp_x;
        y_dis=temp_y;
    }
    return res;
}



int main(){
    // vector<vector<int>>stockPrices= {{1,7},{2,6},{3,5},{4,4},{5,4},{6,3},{7,2},{8,1}};
     vector<vector<int>>stockPrices={{3,4},{1,2},{7,8},{2,3}};
    //vector<vector<int>>stockPrices={{72,98},{62,27},{32,7},{71,4},{25,19},{91,30},{52,73}};
    int ans=minimumLines(stockPrices);
    cout<<ans<<endl;

    system("pause");
    return 0;
}