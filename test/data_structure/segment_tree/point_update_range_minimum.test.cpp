#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "../../../lib/template.cpp"
#include "../../../lib/data_structure/segment_tree.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q; cin >> n >> q;
  SegmentTree<int> st(
      n,
      [](int a, int b){return min(a, b);},
      [](int a, int b){return b;},
      INF
      );
  REP(i, q) {
    int t; cin >> t;
    int x, y; cin >> x >> y;
    if(t == 0) {
      st.update(x, y);
    } else {
      y++;
      cout << st.query(x, y) << endl;
    }
  }
}
