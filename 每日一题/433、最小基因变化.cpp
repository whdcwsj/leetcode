#include<bits/stdc++.h>
using namespace std;

/*同127单词接龙*/

//BFS
//直接从bank中删除已经遇到过的字符串。
int minMutation(string start, string end, vector<string>& bank) {
    queue<string>q;
    int m=start.size();
    q.push(start);
    int num=0;
    while(!q.empty()){
        //记录当前是第几层
        int n=q.size();
        for(int i=0;i<n;i++){
            auto temp=q.front();
            q.pop();
            if(temp==end) return num;
            for(int j=0;j<m;j++){
                for(char c:{'A','C','G','T'}){
                    // string s=temp.substr(0,i)+c+temp.substr(i+1);
                    string s=temp;
                    s[j]=c;
                    //与temp一样,跳过本层for循环
                    if(s==temp) continue;
                    for(int k=0;k<bank.size();k++){
                        if(bank[k]==s){
                            q.push(s);
                            bank.erase(bank.begin()+k);
                            break;
                        }
                    }
                }
            }
        }
        num++;
    }
    return -1;
}


//BFS
//解法2：使用 set 保存所有已经遇到过的字符串
int minMutation(string start, string end, vector<string>& bank){
    //记录遇到过的字符串
    unordered_set<string>bank_set(bank.begin(),bank.end());
    //记录摸个字符串是否遇到过
    unordered_set<string>visited;
    queue<string>q;
    q.push(start);
    int m=start.size();
    int num=0;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            auto temp=q.front();
            q.pop();
            if(temp==end) return num;
            for(int j=0;j<m;j++){
                for(char c:"ACGT"){
                    string s=temp;
                    s[j]=c;
                    if(bank_set.count(s) && !visited.count(s)){
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }
        num++;
    }
    return -1;
}


int main(){
    string start = "AACCGGTT", end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    int ans=minMutation(start,end,bank);
    cout<<ans<<endl;

    system("pause");
    return 0;
}