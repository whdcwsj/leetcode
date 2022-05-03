#include <bits/stdc++.h>
using namespace std;

/*
红色与蓝色的点，分布在不同的位置，给定查询区间，判断是红>蓝，红==蓝，红<蓝
*/

// 通过lower_bound找到区间的左右位置
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> red(n), blue(m);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> blue[j];
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int q;
    cin >> q;
    int left, right;
    vector<long long> res(3);
    while (q--)
    {
        cin >> left >> right;
        auto redleft = lower_bound(red.begin(), red.end(), left);
        auto redright = lower_bound(red.begin(), red.end(), right);
        auto redleftcount = redleft - red.begin();
        auto redrightcount = redright - red.begin() + (right == *redright);
        auto redcount = redrightrcount - redleftcount;

        auto blueleft = lower_bound(blue.begin(), blue.end(), left);
        auto blueright = lower_bound(blue.begin(), blue.end(), right);
        auto blueleftcount = blueleft - blue.begin();
        auto bluerightcount = blueright - blue.begin() + (right == *blueright);
        auto bluecount = bluerightrcount - blueleftcount;

        if (bluecount == redcount)
            res[1]++;
        else if (bluecount > redcount)
            res[2]++;
        else
            res[0]++;
    }
    for (auto r : res)
    {
        cout << r << " ";
    }

    system("pause");
    return 0;
}

// 网上的线段树做法

// #include<bits/stdc++.h>
// #define _for(i,j,k) for(int i=j;i<k;i++)
// using namespace std;
// // 区间修改，区间查询
// class TreeArray {
// private:
//  int n;
//  vector<int> tree1;
//  vector<int> tree2;

//  inline int lowbit(int x) {
//      return x & (-x);
//  }

//  void updata(int i, int val) {
//      for (int p = i; i <= n; i += lowbit(i)) {
//          tree1[i] += val;
//          tree2[i] += p * val;
//      }
//  }

//  int query(int i) {
//      int sum = 0;
//      for (int n = i; i > 0; i -= lowbit(i)) {
//          sum += (n + 1) * tree1[i] - tree2[i];
//      }
//      return sum;
//  }

// public:
//  TreeArray() {}
//  TreeArray(int n) :n(n), tree1(n + 1), tree2(n + 1) {}

//  // 区间修改
//  void rangeUpdate(int left, int right, int val) {
//      updata(left, val);
//      updata(right + 1, -val);
//  }
//  // 区间查询
//  int rangeQuery(int left, int right) {
//      return query(right) - query(left - 1);
//  }

// };

// // P4 100%
// int main() {
//  int n, m, t, q, le, re; cin >> n >> m;
//  vector<int> r(n), b(m);
//  set<int>s;
//  _for(i, 0, n) {
//      cin >> r[i];
//      s.insert(r[i]);
//  }
//  _for(i, 0, m) {
//      cin >> b[i];
//      s.insert(b[i]);
//  }
//  cin >> q;
//  vector<vector<int>> que;
//  _for(i,0,q) {
//      cin >> le >> re;
//      que.push_back({ le,re });
//      s.insert(le);
//      s.insert(re);
//  }
//  int id = 1;
//  unordered_map<int, int> mid;
//  for (auto i : s)
//      mid[i] = id++;
//  TreeArray red(id), blue(id);
//  _for(i, 0, n)
//      red.rangeUpdate(mid[r[i]], mid[r[i]], 1);
//  _for(i, 0, m)
//      blue.rangeUpdate(mid[b[i]], mid[b[i]], 1);

//  int nr, nb, an = 0, bn = 0, cn = 0;
//  _for(i, 0, q) {
//      nr = red.rangeQuery(mid[que[i][0]], mid[que[i][1]]);
//      nb = blue.rangeQuery(mid[que[i][0]], mid[que[i][1]]);
//      if (nr > nb)an++;
//      else if (nr == nb) bn++;
//      else cn++;
//  }
//  cout << an << " " << bn << " " << cn;
//  system("pause");
//  return(0);
// }