#include <bits/stdc++.h>

using namespace std;
int a, b, c;

double cal(double x) {
    return x * (x * (x + a) + b) - c;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        double l = 0, r = 1000;
        while (r - l > 0) {
            auto x = (l + r) / 2;
            auto t = cal(x);
            if (abs(t) < 0.0000001) {
                cout << fixed << setprecision(8) << x << endl;
                break;
            }
            if (t > 0) {
                r = x;
            } else {
                l = x;
            }
        }
    }
    system("pause");
    return 0;
}