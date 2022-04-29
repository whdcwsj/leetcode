#include <bits/stdc++.h>
using namespace std;

// 给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
// 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
// 所以第二小的数字是 10。

//注意，这道题的n的最大值是1e9，按照386的作法，一个一个按顺序求值，会超时
//十叉树

//怎么确定一个前缀下所有子节点的个数？
//如果第 k 个数在当前的前缀下，怎么继续往下面的子节点找？
//如果第 k 个数不在当前的前缀，即当前的前缀比较小，如何扩大前缀，增大寻找的范围？

//计算当前前缀下的子节点数目
//用下一个前缀的起点减去当前前缀的起点
long long getNum(long long prefix, long long n)
{
    long long cur = prefix;
    long long next = prefix + 1;
    long long count = 0;
    while (cur <= n)
    {
        //存在cur<=n，但是next>n的情况
        //注意要n+1，比如n=12，前缀为1，1,10,11,12，共4个
        count += min(n + 1, next) - cur;
        cur *= 10;
        next *= 10;
    }
    return count;
}


// int findKthNumber(int n, int k)
// {
//     //已经经过的元素个数
//     long long cur = 0;
//     long long prefix = 1;
//     while (true)
//     {
//         //找到第K个元素，前面经过K-1个元素
//         if(cur==k-1){
//             break;
//         }
//         long long count = getNum(prefix, n);
//         //第k个数在当前前缀的范围内
//         if (cur + count >= k)
//         {
//             prefix *= 10;
//             //上一个的一个数字也要加上去
//             cur++;
//         }
//         //第K个数不在当前前缀范围内
//         else if (cur + count < k)
//         {
//             prefix++;
//             cur += count;
//         }
//     }
//     return prefix;
// }

int findKthNumber(int n,int k){
    long long cur=1;
    //还剩下k--个节点，还没有访问
    k--;
    while(k>0){
        long long step=getNum(cur,n);
        if(step<=k){
            k-=step;
            cur++;
        }else{
            cur=cur*10;
            k--;
        }
    }
    return cur;
}

int main()
{
    int n = 13;
    int k = 2;
    int res = findKthNumber(n, k);

    cout << res << endl;

    system("pause");
    return 0;
}