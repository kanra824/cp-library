template<class M>
class SegmentTree {
  using F = function<M(M, M)>;
  using G = function<M(M, M)>;
  using CHECK_F = function<bool(M)>;

  F f;
  G g;
  CHECK_F check_f;
  M e = numeric_limits<M>::max();

  int n;
  vector<M> node;

  void init(int sz, F ff, G gg) {
    f = [=](M a, M b) {
      if (a == e) {
        return b;
      } else if (b == e) {
        return a;
      } else {
        return ff(a, b);
      }
    };

    g = [=](M a, M b) {
      if (a == e) {
        return b;
      } else if (b == e) {
        return a;
      } else {
        return gg(a, b);
      }
    };

    n = 1;
    while (n < sz) {
      n <<= 1;
    }
    node.resize(2 * n, e);
  }

  M query(int l, int r, int a, int b, int k) {
    if (l <= a && b <= r) {
      return node[k];
    }
    if (r <= a || b <= l) {
      return e;
    }

    M val1 = query(l, r, a, (a + b) / 2, 2 * k);
    M val2 = query(l, r, (a + b) / 2, b, 2 * k + 1);

    return f(val1, val2);
  }

  int satisfy_right(int l, int r, int x, int a, int b, int k) {
    if (!check_f(node[k]) || r <= a || b <= l) {
      return -1;
    }
    if (k >= n) {
      return k - n;
    }

    int idx1 = satisfy_right(l, r, x, (a + b) / 2, b, 2 * k + 1);
    if (idx1 == -1) {
      return satisfy_right(l, r, x, a, (a + b) / 2, 2 * k);
    } else {
      return idx1;
    }
  }

  int satisfy_left(int l, int r, int x, int a, int b, int k) {
    if (!check_f(node[k]) || r <= a || b <= l) {
      return -1;
    }
    if (k >= n) {
      return k - n;
    }

    int idx1 = satisfy_left(l, r, x, a, (a + b) / 2, 2 * k);
    if (idx1 == -1) {
      return satisfy_left(l, r, x, (a + b) / 2, b, 2 * k + 1);
    } else {
      return idx1;
    }
  }

public:

  /*
    sz: サイズ
    ff: マージに用いる関数
    gg: 更新に用いる関数
    init_val: 初期値

    結合則を満たす必要がある

    O(n)
    ex: range Update range Sum
    SegmentTree(
      n,
      [](int a, int b){return a + b;},
      [](int a, int b){return b;},
      INF
    );
  */
  SegmentTree(int sz, F ff, G gg, M init_val) {
    init(sz, ff, gg);
    for (int i = n; i < n + sz; i++) {
      node[i] = init_val;
    }
    for (int i = n - 1; i >= 1; i--) {
      node[i] = g(node[2 * i], node[2 * i + 1]);
    }
  }


  /*

   O(n)

   ex: range Upd range Sum
   SegmentTree(
      n,
      [](int a, int b){return a + b;},
      [](int a, int b){return b;},
      v
   );
  */
  SegmentTree(int sz, F ff, G gg, vector<M> v) {
    init(sz, ff, gg);
    for (int i = n; i < n + sz; i++) {
      node[i] = v[i - n];
    }
    for (int i = n - 1; i >= 1; i--) {
      node[i] = g(node[2 * i], node[2 * i + 1]);
    }
  }

  /*
   *
   O(log n)
   */
  void update(int idx, M val) {
    idx = idx + n;
    node[idx] = g(node[idx], val);
    while (idx >>= 1) {
      node[idx] = f(node[2 * idx], node[2 * idx + 1]);
    }
  }

  /*
   *
   O(log n)
   */
  M query(int l, int r) {
    return query(l, r, 0, n, 1);
  }

  /*
   *
   check_f: M -> bool
   [l, r) の要素について、check_fを満たすような最も右の要素を求める。

   [l, r) のある要素についてcheck_fがtrueになるならばcheck_f(query(l, r)) がtrueになる
   を満たす必要がある
   */
  int satisfy_right(int l, int r, M x, CHECK_F check_f_in) {
    check_f = move(check_f_in);
    return satisfy_right(l, r, x, 0, n, 1);
  }

  /*
   *
   [l, r) の要素について、check_f を満たすような最も左の要素を求める。

   check_fの条件はrightといっしょ
   */

  int satisfy_left(int l, int r, M x, CHECK_F check_f_in) {
    check_f = move(check_f_in);
    return satisfy_left(l, r, x, 0, n, 1);
  }
};
