#include<bits/stdc++.h>
using namespace std;


//可以双指针贪心，赋值大法
//时间复杂度：O(n)
//空间复杂度：O(1)
vector<int> diStringMatch(string s) {
    int n=s.size();
    int low=0;
    int high=n;
    vector<int>res(n+1);
    for(int i=0;i<n;i++){
        if(s[i]=='I'){
            res[i]=low;
            low++;
        }else{
            res[i]=high;
            high--;
        }
    }
    //此时low与high相同
    res[n]=low;
    return res;
}

int main(){
    string s = "IDID";
    vector<int>ans=diStringMatch(s);
    for(auto c:ans){
        cout<<c<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}