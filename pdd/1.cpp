#include <bits/stdc++.h>
using namespace std;

int n;

//每个数位各不相同
int main()
{
    cin >> n;
    if (n > 45)
    {
        cout << -1 << endl;
    }
    else if (n >= 1 && n <= 9)
    {
        cout << n << endl;
    }
    else if (n >= 10 && n <= 17)
    {
        int temp = (n - 9) * 10;
        temp += 9;
        cout << temp << endl;
    }
    else if (n >= 18 && n <= 24)
    {
        int temp = (n - 17) * 100;
        temp += 89;
        cout << temp << endl;
    }
    else if (n >= 25 && n <= 30)
    {
        int temp = (n - 24) * 1000;
        temp += 789;
        cout << temp << endl;
    }
    else if (n >= 31 && n <= 35)
    {
        int temp = (n - 30) * 10000;
        temp += 6789;
        cout << temp << endl;
    }
    else if (n >= 36 && n <= 39)
    {
        int temp = (n - 35) * 1e5;
        temp += 56789;
        cout << temp << endl;
    }
    else if (n >= 40 && n <= 42)
    {
        int temp = (n - 39) * 1e6;
        temp += 456789;
        cout << temp << endl;
    }
    else if (n >= 43 && n <= 44)
    {
        int temp = (n - 42) * 1e7;
        temp += 3456789;
        cout << temp << endl;
    }
    else if (n==45)
    {
        int temp = (n - 44) * 1e8;
        temp += 23456789;
        cout << temp << endl;
    }

    system("pause");
    return 0;
}