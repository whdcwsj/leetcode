#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<string>temp_nums1;
    vector<string>temp_nums2;
    vector<int>nums1;
    vector<int>nums2;

    string s1;
    cin>>s1;
    stringstream ss1(s1);
    string temp1;
    while(getline(ss1,temp1,',')){
        temp_nums1.push_back(temp1);
    }
    int m=stoi(temp_nums1[0]);
    string temp11=temp_nums1.back();
    stringstream ss2(temp11);
    string temp2;
    while(getline(ss2,temp2,' ')){
        nums1.push_back(stoi(temp2));
    }

    string s2;
    cin>>s2;
    stringstream ss3(s2);
    string temp3;
    while(getline(ss3,temp3,',')){
        temp_nums2.push_back(temp3);
    }
    int n=stoi(temp_nums2[0]);
    string temp22=temp_nums2.back();
    stringstream ss4(temp22);
    string temp4;
    while(getline(ss4,temp4,' ')){
        nums2.push_back(stoi(temp4));
    }

    cout<<"wang"<<endl;

    system("pause");
    return 0;
}