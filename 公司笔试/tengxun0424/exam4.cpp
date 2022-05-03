#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> red(n), blue(m);
    for (int i = 0; i < n; ++i) {
        cin >> red[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> blue[i];
    }
    std::sort(red.begin(), red.end());
    std::sort(blue.begin(), blue.end());
    int q;
    cin >> q;
    int l, r;
    vector<long long> res(3);
    while (q--) {
        cin >> l >> r;
        auto redl = lower_bound(red.begin(), red.end(), l);
        auto redr = lower_bound(red.begin(), red.end(), r);
        auto redlcount = redl - red.begin();
        auto redrcount = redr - red.begin() + (r == *redr);
        auto redcount = redrcount - redlcount;

        auto bluel = lower_bound(blue.begin(), blue.end(), l);
        auto bluer = lower_bound(blue.begin(), blue.end(), r);
        auto bluelcount = bluel - blue.begin();
        auto bluercount = bluer - blue.begin() + (r == *bluer);
        auto bluecount = bluercount - bluelcount;
        if (bluecount == redcount)
            res[1]++;
        else if (bluecount > redcount)
            res[2]++;
        else
            res[0]++;
    }
    for (auto r: res) {
        cout << r << " ";
    }
    return 0;
}