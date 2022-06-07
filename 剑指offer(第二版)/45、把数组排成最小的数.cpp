#include<bits/stdc++.h>
using namespace std;


//排序规则很难写
//若拼接字符串x+y>y+x,则x“大于” yy ；
//反之,若x+y<y+x,则x“小于”y


//1、内置函数方法
static bool cmp(string&a, string&b){
    return a+b<b+a;
}

string minNumber(vector<int>& nums) {
    vector<string>str;
    string res="";
    for(int i=0;i<nums.size();i++){
        str.push_back(to_string(nums[i]));
    }
    sort(str.begin(),str.end(),cmp);
    for(int i=0;i<str.size();i++){
        res.append(str[i]);
    }
    return res;
}


//2、快排方法(有问题)
void quickSort(vector<string>&str,int left,int right){
    if(left>=right) return;
    int i=left;
    int j=right;
    while(i<j){
        while(i<j && str[j]+str[left]>=str[left]+str[j]) j--;
        while(i<j && str[i]+str[left]<=str[left]+str[i]) i++;
        swap(str[i],str[j]);
    }
    swap(str[i],str[j]);
    quickSort(str, left, i - 1);
    quickSort(str, i + 1, right);

}


string minNumber(vector<int>& nums) {
    vector<string> str;
    for(int i = 0; i < nums.size(); i++)
        str.push_back(to_string(nums[i]));
    quickSort(str, 0, str.size() - 1);
    string res;
    for(string s : str)
        res.append(s);
    return res;
}




int main(){
    //3033459
    vector<int>nums={3,30,34,5,9};
    string ans=minNumber(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}
