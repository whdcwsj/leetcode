#include<bits/stdc++.h>
using namespace std;



double calculateTax(vector<vector<int>>& brackets, int income) {
    double res=0.0;
    double cur=0.0;
    int n=brackets.size();
    for(int i=0;i<n;i++){
        if(income>brackets[i][0]){
            res+=(brackets[i][0]-cur)*(double)brackets[i][1];
            cur=brackets[i][0];
        }
        else{
            res+=(income-cur)*(double)brackets[i][1];
            break;
        }
    }
    return res/100.0;
}


int main(){
    vector<vector<int>> brackets={{3,50},{7,10},{12,25}};
    int income = 10;
    double ans=calculateTax(brackets,income);
    cout<<ans<<endl;

    system("pause");
    return 0;
}