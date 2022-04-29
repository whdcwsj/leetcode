/*
问题：
给定一个整数 n, 返回从 1 到 n 的字典顺序。
例如，
给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
*/
#include<bits/stdc++.h>
using namespace std;


//可以用时间复杂度O(n)实现
//空间复杂度O(1)
//迭代做法
vector<int> lexicalOrder(int n){
    vector<int>res(n);
    int num=1;
    for(int i=0;i<n;i++){
        res[i]=num;
        if(num*10<=n){
            //下一个字典序的数字
            num*=10;
        }else{
            //当前数字位次已经搜索结束，以n=100为例
            while(num%10==9 || num+1>n){
                num/=10;
            }
            num++;
        }
    }
    return res;
}


//递归作法
/*
将问题转换为图集合问题，使用DFS遍历。
（1）总共有9张图，1-9作为图的搜索的起始位置。
（2）从起点开始深度优先遍历，将满足条件的值进行记录。
（3）结束条件：节点值大于给定的结尾值。及n。
*/

vector<int>res;
void dfs(int cur,int n){
    if(cur>n) return;
    res.push_back(cur);
    for(int i=0;i<=9;i++){
        dfs(cur*10+i,n);
    }
}

vector<int> lexicalOrder(int n){
    for(int i=1;i<=9;i++){
        dfs(i,n);
    }
    return res;
}


int main(){
    int n=13;
    vector<int>res=lexicalOrder(n);
    for(auto&a:res){
        cout<<a<<" ";
    }

    system("pause");
    return 0;
}