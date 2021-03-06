#include<bits/stdc++.h>

struct PartiallyPersistentUnionFind {
  const int INF = INT_MAX;
  int n;
  int now = 0;
  std::vector<int> time;
  std::vector<int> par;
  std::vector<std::vector<std::pair<int, int>>> sz;

  PartiallyPersistentUnionFind(int n): n(n) {
    time.resize(n, INF);
    par.resize(n, -1);
    sz.resize(n, std::vector<std::pair<int, int>>(1, {0, 1}));
  }

  // O(log(n))
  // xとyをマージする
  int unite(int x, int y) {
    ++now;
    x = find(now, x);
    y = find(now, y);
    if(x == y) return now;
    if(par[x] < par[y]) std::swap(x, y);
    par[y] += par[x];
    par[x] = y;
    sz[y].emplace_back(now, -par[y]);
    time[x] = now;
    return now;
  }

  // O(log(n))
  // 時刻tにおけるxのrootを見つける
  int find(int t, int x) {
    if(time[x] > t) return x;
    else return find(t, par[x]);
  }

  // O(log(n))
  // 時刻tにおいてxとyが同じかどうか判定する
  bool same(int t, int x, int y) {
    return find(t, x) == find(t, y);
  }

  // O(log(n))
  // 時刻tにおけるxを含む連結成分のサイズを取得する
  int size(int t, int x) {
    x = find(t, x);
    auto it = upper_bound(sz[x].begin(), sz[x].end(), std::make_pair(t, INF));
    it--;
    return it->second;
  }
};