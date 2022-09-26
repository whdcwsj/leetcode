#include<bits/stdc++.h>
using namespace std;
int length;
void PrintSolutions(int *flag)
{
    for (int i=0; i<length; i++)
    {
        if (flag[i] == 1)
        {
            cout << i+1 << "  ";
        }
    }
    cout << endl;
}
 
void BagProblem(int m, int n, int *flag)
{
    if(n<1 || m<1)
        return;
    if(m < n)
        n = m;
    if (n == m)
    {
        flag[n-1] = 1;
        PrintSolutions(flag);
        flag[n-1] = 0;
    }
    flag[n-1] = 1;
    BagProblem(m-n, n-1, flag);
    flag[n-1] = 0;
 
    BagProblem(m, n-1, flag);
}
 
int main(int argc, char* argv[])
{
    int m, n;
    cout << "Please input the m and n:" << endl;
    cin >> m >> n;
    cout << "The solution is:" << endl;
    length = n;
    int *flag = (int *)malloc(sizeof(int)*n);
    memset(flag, 0, sizeof(flag));
    BagProblem(m,n,flag);
    //delete flag;//这个地方犯了一个原则性的错误 new和delete成对使用， malloc应该和free成对使用，要不然就会造成内存泄露
    free(flag);
    return 0;
}