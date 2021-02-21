struct UnionFind {
  int n;
  std::vector<int> par;

  UnionFind(int n): n(n) {
    par.resize(n, -1);
  }

  int root(int x) {
    return par[x] < 0 ? x : par[x] = root(par[x]);
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;

    if(par[x] < par[y]) swap(x, y);

    par[y] += par[x];
    par[x] = y;
  }
};
