#include <bits/stdc++.h>
using namespace std;

/*
多多鸡打算造一本自己的电子字典，里面的所有单词都只由a和b组成。
每个单词的组成里a的数量不能超过N个且b的数量不能超过M个。
多多鸡的幸运数字是K，它打算把所有满足条件的单词里的字典序第K小的单词找出来，作为字典的封面。
*/

//避免重复计算，建立一个字典
map<pair<int, int>, unsigned long long> wang;

// dp[n][m] = dp[n][m-1] + dp[n][m-1] + 2
// n个a，m个b
unsigned long long getNum(int n, int m)
{
    if (wang.count({n, m}))
        return wang[{n, m}];
    // m为0的话
    if (!m)
    {
        wang[{n, m}] = n;
    }
    else if (!n)
    {
        wang[{n, m}] = m;
    }
    else
    {
        wang[{n, m}] = getNum(n - 1, m) + getNum(n, m - 1) + 2;
    }
    return wang[{n, m}];
}

int main()
{
    long long k;
    int n, m;
    cin >> n >> m >> k;

    //已经经过的元素个数
    string cur = "a";
    n--;
    k--;
    while (k > 0 && (m || n))
    {
        //子树的个数
        //这里判断的时候要+1，因为还有为首的一个字母
        unsigned long long count = getNum(n, m) + 1;
        // k在当前子树中
        if (k < count)
        {
            k--;
            if (n)
            {
                cur += 'a';
                n--;
            }
            else
            {
                cur += 'b';
                m--;
            }
        }
        //k不在当前子树中，在下一个子树中
        else
        {
            k-=count;
            n++;
            m--;
            //相当于把a变成b
            cur.back()++;
        }
    }
    cout<<cur<<endl;

    system("pause");
    return 0;
}