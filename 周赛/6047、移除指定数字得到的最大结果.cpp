#include<bits/stdc++.h>
using namespace std;


string removeDigit(string number, char digit) {
    vector<string>nums;
    int index=0;
    while(true){
        int pos=number.find_first_of(digit,index);
        if(pos==string::npos){
            break;
        }
        index=pos+1;
        string temp=number;
        temp.erase(temp.begin()+pos);
        //cout<<"index:"<<index<<endl;
        //cout<<stoi(temp)<<endl;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());
    string res=nums[nums.size()-1];
    return res;
}


int main(){

    string number = "1231";
    char digit = '1';
    string wang=removeDigit(number,digit);
    cout<<wang<<endl;


    system("pause");
    return 0;
}