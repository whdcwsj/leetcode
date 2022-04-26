#include <bits/stdc++.h>
using namespace std;

int a, b, c;

double cal(doble x)
{
    return x * (x * (x + a) + b) - c;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> c;
        double left = 0, right = 1000;
        while (right - left > 0)
        {
            double mid = left + (right - left) / 2.0;
            double temp = cal(mid);
            if (abs(temp) < 1e-8)
            {
                cout << fixed << setprecision(8) << mid << endl;
                break;
            }
            if (temp > 0)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
    }
    system("pause");
    return 0;
}