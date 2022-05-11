#include<bits/stdc++.h>
using namespace std;



vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size();
    if(m==0) return {};
    int n=matrix[0].size();
    if(n==0) return {};
    int up=0,down=m-1;
    int left=0,right=n-1;
    vector<int>res;
    while(true){
        for(int i=left;i<=right;i++) res.push_back(matrix[up][i]);
        if(++up>down) break;
        for(int j=up;j<=down;j++) res.push_back(matrix[j][right]);
        if(--right<left) break;
        for(int i=right;i>=left;i--) res.push_back(matrix[down][i]);
        if(--down<up) break;
        for(int j=down;j>=up;j--) res.push_back(matrix[j][left]);
        if(++left>right) break;
    }
    return res;
}



int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int>ans=spiralOrder(matrix);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}