template <class M>
struct SegmentTree {
  using F = function<M(M, M)>;
  using G = function<M(M, M)>;

  F f;
  G g;
  M e = numeric_limits<M>::max();

  int n;
  vector<int> node;

  SegmentTree(int sz, F ff, G gg, M init_val) {
    f = [&](M a, M b) {
      if(a == e) {
        return b;
      } else if(b == e) {
        return a;
      } else {
        return ff(a, b);
      }
    };

    g = [&](M a, M b) {
      if(a == e) {
        return b;
      } else if(b == e) {
        return a;
      } else {
        return gg(a, b);
      }
    };

    n = 1;
    while(n < sz) {
      n <<= 1;
    }
    node.resize(2*n, e);
    for(int i=n;i<n+sz;i++) {
      node[i] = init_val;
    }
    for(int i=n-1;i>=1;i--) {
      node[i] = g(node[2*i], node[2*i+1]);
    }
  }

  void update(int idx, int val) {
    idx = idx + n;
    node[idx] = g(node[idx], val);
    while(idx >>= 1) {
      node[idx] = g(node[2*idx], node[2*idx+1]);
    }
  }

  int query(int l, int r, int a, int b, int k) {
    if(l <= a && b <= r) {
      return node[k];
    }
    if(r <= a || b <= l) {
      return e;
    }

    int val1 = query(l, r, a, (a+b)/2, 2*k);
    int val2 = query(l, r, (a+b)/2, b, 2*k+1);

    return f(val1, val2);
  }

  int query(int l, int r) {
    return query(l, r, 0, n, 1);
  }
};
