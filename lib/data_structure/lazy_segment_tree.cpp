template <class M, class OM>
struct LazySegmentTree {
  int n;
  vector<M> node;
  vector<OM> lazy;

  using F = function<M(M, M)>;
  using G = function<M(M, OM)>;
  using H = function<OM(OM, OM)>;

  F f;
  G g;
  H h;

  M e;
  OM oe;

  LazySegmentTree(int sz, F ff, G gg, H hh, M ee, OM oeoe):
  f(ff),
  g(gg),
  h(hh),
  e(ee),
  oe(oeoe)
  {
    n = 1;
    while(n < sz) {
      n <<= 1;
    }
    node.resize(2*n, e);
    lazy.resize(2*n, oe);
  }

  LazySegmentTree(int sz, F ff, G gg, H hh, M ee, OM oeoe, vector<M> v):
  f(ff),
  g(gg),
  h(hh),
  e(ee),
  oe(oeoe)
  {
    n = 1;
    while(n < sz) {
      n <<= 1;
    }
    node.resize(2*n, e);
    lazy.resize(2*n, oe);
    REP(i, SZ(v)) {
      node[i+n] = v[i];
    }
    RREP(i, n-1) {
      node[i] = f(node[2*i], node[2*i+1]);
    }
  }

  void propagate(int a, int b, int k) {
    node[k] = g(node[k], lazy[k]);
    if(2*k < 2*n) lazy[2*k] = h(lazy[2*k], lazy[k]);
    if(2*k+1 < 2*n) lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
    lazy[k] = oe;
  }

  void update(int l, int r, int a, int b, int k, OM x) {
    propagate(a, b, k);
    if(l <= a && b <= r) {
      lazy[k] = h(lazy[k], x);
      propagate(a, b, k);
      return;
    }
    if(b <= l || r <= a) {
      return;
    }

    update(l, r, a, (a+b)/2, 2*k, x);
    update(l, r, (a+b)/2, b, 2*k+1, x);
    node[k] = f(node[2*k], node[2*k+1]);
  }

  void update(int l, int r, OM x) {
    update(l, r, 0, n, 1, x);
  }

  M query(int l, int r, int a, int b, int k) {
    propagate(a, b, k);

    if(l <= a && b <= r) {
      return node[k];
    }
    if(b <= l || r <= a) {
      return e;
    }

    M val1 = query(l, r, a, (a+b)/2, 2*k);
    M val2 = query(l, r, (a+b)/2, b, 2*k+1);
    return f(val1, val2);
  }

  M query(int l, int r) {
    return query(l, r, 0, n, 1);
  }

};
