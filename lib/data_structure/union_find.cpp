struct UnionFind {
  int n;
  int cnt;
  std::vector<int> par;

  UnionFind(int n): n(n), cnt(n) {
    par.resize(n, -1);
  }

  // ならしでO(α(n))
  int root(int x) {
    return par[x] < 0 ? x : par[x] = root(par[x]);
  }

  // ならしでO(α(n))
  bool same(int x, int y) {
    return root(x) == root(y);
  }

  // ならしで O(α(n))
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;
    cnt--;

    if(par[x] < par[y]) swap(x, y);

    par[y] += par[x];
    par[x] = y;
  }

  // O(1)
  int size(int x) {
    return -par[root(x)];
  }
};
