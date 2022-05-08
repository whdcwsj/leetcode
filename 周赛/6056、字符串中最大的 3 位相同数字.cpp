#include<bits/stdc++.h>
using namespace std;


string largestGoodInteger(string num) {
      int length=1;
      int n=num.size();
      vector<string>res;
      for(int i=1;i<n;i++){
          if(num[i]==num[i-1]){
              length++;
          }else{
              length=1;
          }
          if(length==3){
              res.push_back(num.substr(i-2,3));
              length=1;
              i++;
          }
      }
      if(res.size()==0) return "";
      sort(res.begin(),res.end());
      return *res.rbegin();
}


int main(){
    string num = "6777133339";
    string ans=largestGoodInteger(num);
    cout<<ans<<endl;

    system("pause");
    return 0;
}