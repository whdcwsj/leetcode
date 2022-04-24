#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> d, u, mdata;
unordered_map<int, int> ump;
int n;

bool check(int x) {
    if (x == 1)return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

long long calRes(int x) {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        if (mdata[i] > x) {
            res += abs(ump[d[i]] - ump[x]) + 1;
        } else if (mdata[i] < x) {
            res += abs(ump[u[i]] - ump[x]) + 1;
        }
    }
    return res;
}

int main() {
    unordered_map<int, long long> res_map;
    cin >> n;
    if (n == 1) {
        cin >> n;
        cout << !check(n) << endl;
        return 0;
    }
    mdata.resize(n);
    d.resize(n);
    u.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> mdata[i];
    }
    sort(mdata.begin(), mdata.end());
    int index = 0;
    for (int i = mdata.front();; ++i) {
        if (check(i)) {
            ump[i] = index++;
            v.push_back(i);
            if (i >= mdata.back())
                break;
        }
    }

    //分别记录比数字小的最大质数，和比数字大的最小质数
    for (int i = 0; i < n; ++i) {
        for (int j = mdata[i] - 1; j >= 0; --j) {
            if (ump.count(j)) {
                d[i] = j;
                break;
            }
        }
        for (int j = mdata[i] + 1; j <= v.back(); ++j) {
            if (ump.count(j)) {
                u[i] = j;
                break;
            }
        }
    }

    int l = 0, r = v.size() - 1;
    while (l <= r) {
        auto t = (l + r) / 2;
        long long x;
        if (!res_map.count(v[t])) {
            res_map[v[t]] = calRes(v[t]);
        }
        x = res_map[v[t]];
        bool y;
        if (t == 0) {
            if (!res_map.count(v[t + 1])) {
                res_map[v[t + 1]] = calRes(v[t + 1]);
            }
            y = res_map[v[t + 1]] <= x;
        } else {
            if (!res_map.count(v[t - 1])) {
                res_map[v[t - 1]] = calRes(v[t - 1]);
            }
            y = res_map[v[t - 1]] >= x;
        }
        if (y) {
            l = t + 1;
        } else {
            r = t-1;
        }
    }
    cout << res_map[v[l - 1]] << endl;
    system("pause");
    return 0;
}