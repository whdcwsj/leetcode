#include <bits/stdc++.h>
using namespace std;


//不断push，只要栈顶元素跟pop一样，就一直弹出
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int m=pushed.size();
    int n=popped.size();
    if(m!=n) return false;
    stack<int>s;
    int index=0;
    for(int i=0;i<m;i++){
        s.push(pushed[i]);
        while(!s.empty() && popped[index]==s.top()){
            s.pop();
            index++;
        }
    }
    return s.empty();
}




int main(){
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    bool ans=validateStackSequences(pushed,popped);
    cout<<ans<<endl;

    system("pause");
    return 0;
}