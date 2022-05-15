#include<bits/stdc++.h>
using namespace std;


int maxConsecutive(int bottom, int top, vector<int>& special) {
    special.push_back(bottom);
    special.push_back(top);
    sort(special.begin(),special.end());
    int maxnum=0;
    for(int i=0;i<special.size()-1;i++){
        int temp;
        if(i==0 || i==special.size()-2){
            temp=special[i+1]-special[i];
        }else{
            temp=special[i+1]-special[i]-1;
        }
        if(temp>maxnum){
            maxnum=temp;
        }
    }
    return maxnum;   
}



int main(){
    int bottom = 2, top = 9;
    vector<int> special = {4,6};
    int ans=maxConsecutive(bottom,top,special);
    cout<<ans<<endl;
    
    system("pause");
    return 0;
}