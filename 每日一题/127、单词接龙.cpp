#include<bits/stdc++.h>
using namespace std;

/*同433最小基因变化*/

//BFS
//把走迷宫问题的4个方向转变成了26个方向
//直接写会超时，将vector换成unordered_set就行
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>wang_wordList(wordList.begin(),wordList.end());
    queue<string>q;
    int m=beginWord.size();
    q.push(beginWord);
    int num=1;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            auto temp=q.front();
            q.pop();
            if(temp==endWord) return num;
            for(int j=0;j<m;j++){
                for(char c='a';c<='z';c++){
                    string s=temp;
                    s[j]=c;
                    //if(s==temp) continue;
                    if(wang_wordList.count(s)){
                        q.push(s);
                        wang_wordList.erase(s);
                    }
                }
            }
        }
        num++;
    }
    return 0;
}



int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int ans=ladderLength(beginWord,endWord,wordList);
    cout<<ans<<endl;

    system("pause");
    return 0;
}