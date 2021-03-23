#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../../lib/template.cpp"
#include "../../../lib/data_structure/lazy_segment_tree.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q; cin >> n >> q;
  using P = pair<ll, int>;
  vector<P> v(n, {0, 1});
  LazySegmentTree<P, ll> st(
      n,
      [](P a, P b){return make_pair(a.first + b.first, a.second + b.second);},
      [](P a, ll b){return make_pair(a.first + a.second * b, a.second);},
      [](ll a, ll b){return a + b;},
      make_pair(0ll, 0),
      0,
      v
      );
  REP(i, q) {
    int k; cin >> k;
    if(k == 0) {
      int a, b, x; cin >> a >> b >> x;
      a--;
      st.update(a, b, x);
    } else {
      int a, b; cin >> a >> b;
      a--;
      cout << st.query(a, b).first << endl;
    }
  }
}