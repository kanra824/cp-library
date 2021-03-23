// とりあえずrange update range sum
struct LazySegmentTree {
  int n;
  vector<ll> node, lazy;

  LazySegmentTree(int sz) {
    n = 1;
    while(n < sz) {
      n <<= 1;
    }
    node.resize(2*n, 0);
    lazy.resize(2*n, INF);
  }

  void propagate(int a, int b, int k) {
    if(lazy[k] != INF) {
      node[k] += lazy[k];
      if(2*k < 2*n) {
        if(lazy[2*k] == INF) lazy[2*k] = lazy[k] / 2;
        else lazy[2*k] += lazy[k] / 2;
      }
      if(2*k < 2*n) {
        if(lazy[2*k+1] == INF) lazy[2*k+1] = lazy[k] / 2;
        else lazy[2*k+1] += lazy[k] / 2;
      }
      lazy[k] = INF;
    }
  }

  void update(int l, int r, int a, int b, int k, int x) {
    propagate(a, b, k);
    if(l <= a && b <= r) {
      if(lazy[k] == INF) lazy[k] = (b - a) * x;
      else lazy[k] += (b - a) * x;
      propagate(a, b, k);
      return;
    }
    if(b <= l || r <= a) {
      return;
    }

    update(l, r, a, (a+b)/2, 2*k, x);
    update(l, r, (a+b)/2, b, 2*k+1, x);
    node[k] = node[2*k] + node[2*k+1];
  }

  void update(int l, int r, int x) {
    update(l, r, 0, n, 1, x);
  }

  ll query(int l, int r, int a, int b, int k) {
    propagate(a, b, k);

    if(l <= a && b <= r) {
      return node[k];
    }
    if(b <= l || r <= a) {
      return 0;
    }

    ll val1 = query(l, r, a, (a+b)/2, 2*k);
    ll val2 = query(l, r, (a+b)/2, b, 2*k+1);
    return val1 + val2;
  }

  ll query(int l, int r) {
    return query(l, r, 0, n, 1);
  }

};
