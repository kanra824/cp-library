#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include "../../../lib/template.cpp"
#include "../../../lib/data_structure/lazy_segment_tree.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q; cin >> n >> q;
  vector<ll> v(n, 0);
  LazySegmentTree<ll, ll> st(
      n,
      [](ll a, ll b){return min(a, b);},
      [](ll a, ll b){return a == LINF ? b : a + b;},
      [](ll a, ll b){return a + b;},
      LINF,
      0,
      v
  );
  REP(i, q) {
    int k; cin >> k;
    if(k == 0) {
      int a, b, x; cin >> a >> b >> x;
      b++;
      st.update(a, b, x);
    } else {
      int a, b; cin >> a >> b;
      b++;
      cout << st.query(a, b) << endl;
    }
  }
}
