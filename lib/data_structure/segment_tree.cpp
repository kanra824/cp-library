struct SegmentTree {
  int n;
  vector<int> node;

  SegmentTree(int sz) {
    n = 1;
    while(n < sz) {
      n <<= 1;
    }
    node.resize(2*n, 0);
  }

  void update(int idx, int val) {
    idx = idx + n - 1;
    node[idx] += val;
    while(idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2*idx+1] + node[2*idx+2];
    }
  }

  int query(int l, int r, int a, int b, int k) {
    if(l <= a && b <= r) {
      return node[k];
    }
    if(r <= a || b <= l) {
      return 0;
    }

    int val1 = query(l, r, a, (a+b)/2, 2*k+1);
    int val2 = query(l, r, (a+b)/2, b, 2*k+2);

    return val1 + val2;
  }

  int query(int l, int r) {
    return query(l, r, 0, n, 0);
  }
};
