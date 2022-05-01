#include<bits/stdc++.h>
using namespace std;


int minimumCardPickup(vector<int>& cards) {
    if(cards.size()==1) return -1;
    map<int,int>wang;
    int start=0;
    int minlength=INT_MAX;
    for(int i=0;i<cards.size();i++){
        wang[cards[i]]++;
        if(wang[cards[i]]>1){
            for(int j=start;j<i;j++){
                wang[cards[j]]--;
                if(wang[cards[j]]==1){
                    minlength=min(minlength,i-j+1);
                    start=j+1;
                    break;
                }
            }
        }
    }
    return minlength==INT_MAX?-1:minlength;
}


int main(){
    //vector<int> cards = {3,4,2,3,4,7};
    //vector<int> cards ={1,0,5,3};
    vector<int> cards ={95,11,8,65,5,86,30,27,30,73,15,91,30,7,37,26,55,76,60,43,36,85,47,96,6};
    int hahaha=minimumCardPickup(cards);
    cout<<hahaha<<endl;


    system("pause");
    return 0;
}