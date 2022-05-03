#include<bits/stdc++.h>
using namespace std;

//因为二维数组一定程度有序
//需要从左下到右上去遍历
//时间复杂度：O(n+m)
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target){
    if(matrix.size()==0 || matrix[0].size()==0) return false;
    int n=matrix.size();
    int m=matrix[0].size();
    int i=n-1;
    int j=0;
    while(i>=0 && j<=m-1){
        int cur=matrix[i][j];
        if(cur==target) return true;
        else if(cur<target) j++;
        else i--;
    }
    return false;
}



int main(){
    vector<vector<int>>nums=
    {
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
    };
    int tar=20;
    bool flag=findNumberIn2DArray(nums,tar);
    cout<<flag<<endl;

    system("pause");
    return 0;
}