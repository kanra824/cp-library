#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp"

#include "../../lib/template.cpp"
#include "../../lib/data_structure/segment_tree.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, q; cin >> n >> q;
  SegmentTree<int> st(
      n,
      [](int a, int b) {return a + b;},
      [](int a, int b) {return a + b;},
      0
      );
  REP(i, q) {
    int t; cin >> t;
    int x, y; cin >> x >> y;
    x--;
    if(t == 0) {
      st.update(x, y);
    } else {
      cout << st.query(x, y) << endl;
    }
  }

}

