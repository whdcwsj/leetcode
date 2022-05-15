#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
vector<bool> flag;
vector<string> res;

//1、hash表解法
vector<string> removeAnagrams(vector<string> &words)
{
    int n = words.size();
    if (n == 1)
        return words;
    flag.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (flag[i] == 0)
        {
            res.push_back(words[i]);
        }
        if (i == n - 1)
        {
            break;
        }
        m.clear();
        for (auto &c : words[i])
        {
            m[c - 'a']++;
        }
        if (words[i].size() != words[i + 1].size())
        {
            flag[i + 1] = 0;
        }
        else
        {
            bool temp = 1;
            for (auto &k : words[i + 1])
            {
                m[k - 'a']--;
                if (m[k - 'a'] < 0)
                {
                    temp = 0;
                    break;
                }
            }
            flag[i + 1] = temp;
        }
    }
    return res;
}



//2、字符数组解法
vector<string> removeAnagrams(vector<string> &words){
    string pre="";
    vector<string>res;
    for(auto&word:words){
        string temp=word;
        sort(word.begin(),word.end());
        if(word!=pre){
            res.push_back(temp);
        }
        pre=word;
    }
    return res;
}




int main()
{
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> ans = removeAnagrams(words);
    for (auto &a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}